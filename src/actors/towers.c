/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Create tower for my_radar
*/
#include "my_radar.h"

static int tower_render(radar_t *radar, tower_t *tower)
{
    if (radar->is_hitbox_visibles) {
        sfRenderWindow_drawCircleShape(radar->window, tower->hitbox, 0);
    }
    if (radar->is_sprite_visibles) {
        sfRenderWindow_drawSprite(radar->window, tower->sprite, 0);
    }
    return 0;
}

tower_t *create_tower(sfTexture *texture, sfVector2f pos, double area)
{
    tower_t *new = malloc(sizeof(tower_t));

    new->pos = pos;
    new->area = area;
    new->sprite = sfSprite_create();
    sfSprite_setTexture(new->sprite, texture, 0);
    sfSprite_setPosition(new->sprite, (sfVector2f) {pos.x - 16, pos.y - 32});
    new->hitbox = sfCircleShape_create();
    sfCircleShape_setFillColor(new->hitbox,
        sfColor_fromRGBA(255, 255, 0, 128));
    sfCircleShape_setPosition(new->hitbox,
        (sfVector2f) {pos.x - area, pos.y - area});
    sfCircleShape_setRadius(new->hitbox, new->area);
    sfCircleShape_setOutlineThickness(new->hitbox, 1.f);
    sfCircleShape_setOutlineColor(new->hitbox, sfColor_fromRGB(255, 255, 0));
    new->render = &tower_render;
    new->destroyer = &destroy_tower;
    return new;
}

int destroy_tower(tower_t *tower)
{
    sfSprite_destroy(tower->sprite);
    sfCircleShape_destroy(tower->hitbox);
    free(tower);
    return 0;
}
