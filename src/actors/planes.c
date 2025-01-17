/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Create plane for my_radar
*/
#include "my_radar.h"

static int plane_timer(plane_t *plane)
{
    plane->delta_t = sfClock_restart(plane->clock).microseconds / 1000000.0f;
    return 0;
}

static int plane_mover(radar_t *scene, plane_t *plane)
{
    sfVector2f tomove = fvectmul(plane->vel, plane->delta_t, plane->delta_t);

    if (plane->delay >= 0) {
        plane->delay -= plane->delta_t;
        return 0;
    } else if (!plane->is_launched) {
        scene->stat->planes_launched++;
        plane->is_launched = sfTrue;
    }
    plane->pos.x += tomove.x;
    plane->pos.y += tomove.y;
    plane->pos = (sfVector2f) {my_fmod(plane->pos.x, WIN_W),
        my_fmod(plane->pos.y, WIN_H)};
    sfSprite_setPosition(plane->sprite, plane->pos);
    sfRectangleShape_setPosition(plane->hitbox, plane->pos);
    return 0;
}

static int plane_render(radar_t *radar, plane_t *plane)
{
    if (plane->delay > 0)
        return 0;
    if (radar->is_hitbox_visibles) {
        sfRenderWindow_drawRectangleShape(radar->window, plane->hitbox, 0);
    }
    if (radar->is_sprite_visibles) {
        sfRenderWindow_drawSprite(radar->window, plane->sprite, 0);
    }
    return 0;
}

sfRectangleShape *plane_hitbox(plane_t *plane)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, (sfVector2f) {20, 20});
    sfRectangleShape_setOutlineThickness(rect, 1.0f);
    sfRectangleShape_setOutlineColor(rect, sfGreen);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOrigin(rect, (sfVector2f) {10, 10});
    sfRectangleShape_setRotation(rect, plane->rotation_angle);
    sfRectangleShape_setPosition(rect, plane->pos);
    return rect;
}

static void affect_funcs(plane_t *new)
{
    new->time = &plane_timer;
    new->move = &plane_mover;
    new->render = &plane_render;
    new->destroyer = &destroy_plane;
    return;
}

static sfVector2f get_bdir(sfVector2f pos1, sfVector2f pos2, double speed)
{
    double norme1 = get_norme(pos1, pos2);
    double n2 = get_norme(pos1, (sfVector2f) {pos2.x - WIN_W, pos2.y - WIN_H});

    if (norme1 < n2) {
        return get_dir(pos1, pos2, speed);
    }
    return (sfVector2f) {-1 * get_dir(pos1, pos2, speed).x,
        -1 * get_dir(pos1, pos2, speed).y};
}

plane_t *create_plane(sfTexture *texture, sfVector2f pos, sfVector2f target,
    sfVector2f speedanddelay)
{
    plane_t *new = malloc(sizeof(plane_t));

    new->clock = sfClock_create();
    new->blue_origin = pos;
    new->pos = pos;
    new->target = target;
    new->speed = speedanddelay.x;
    new->delay = speedanddelay.y;
    new->vel = get_dir(new->pos, new->target, new->speed);
    new->sprite = sfSprite_create();
    new->rotation_angle = atan2(new->target.y - new->pos.y,
        new->target.x - new->pos.x) * 180.0 / 3.141592653589793238;
    sfSprite_setTexture(new->sprite, texture, 0);
    sfSprite_setOrigin(new->sprite, (sfVector2f) {10, 10});
    sfSprite_setPosition(new->sprite, new->pos);
    sfSprite_setRotation(new->sprite, new->rotation_angle + 90.f);
    new->hitbox = plane_hitbox(new);
    new->is_launched = sfFalse;
    affect_funcs(new);
    return new;
}

int destroy_plane(plane_t *plane)
{
    sfClock_destroy(plane->clock);
    sfRectangleShape_destroy(plane->hitbox);
    sfSprite_destroy(plane->sprite);
    free(plane);
    return 0;
}
