/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Trafik scene related functions
*/
#include "my_radar.h"

static int is_plane(actor_t *actors)
{
    for (actor_t *temp = actors; temp; temp = temp->next) {
        if (temp->type == PLANE_A) {
            return 1;
        }
    }
    return 0;
}

static void destroy_sprites(actor_t *actor)
{
    if (actor->next)
        destroy_sprites(actor->next);
    switch (actor->type) {
        case PLANE_A:
            PLANE(actor)->destroyer(PLANE(actor));
            break;
        case TOWER_A:
            TOWER(actor)->destroyer(TOWER(actor));
            break;
        default:
            sfSprite_destroy(((teapot_t *) actor->infos)->sprite);
            free(actor->infos);
            break;
    }
    free(actor->name);
    free(actor);
    return;
}

int trafik_destroyer(scene_t *scene)
{
    destroy_sprites(scene->actors);
    sfClock_destroy(scene->clock);
    free(scene);
    return 0;
}

int trafik_time(radar_t *radar)
{
    actor_t *actors = radar->scenes[TRAFIK_S]->actors;

    for (; actors; actors = actors->next) {
        if (actors->type == PLANE_A) {
            PLANE(actors)->time(PLANE(actors));
        }
    }
    return 0;
}

static void check_landed(radar_t *radar, actor_t **actor)
{
    actor_t *actors = *actor;

    if (get_bnorme(PLANE(actors)->blue_origin, PLANE(actors)->target) <=
        get_bnorme(PLANE(actors)->blue_origin, PLANE(actors)->pos)) {
        *actor = actors->next;
        destroy_one_actor(&(radar->scenes[TRAFIK_S]->actors), actors);
        radar->stat->planes_landed++;
    }
}

static void check_medals(radar_t *radar)
{
    for (medals_t *temp = radar->medals; temp; temp = temp->next) {
        if (!temp->is_checked && temp->checker && temp->checker(radar)) {
            temp->is_checked = sfTrue;
            my_printf("Medals gained:\n\t%s:\n\t%s\n",
                temp->name, temp->description);
        }
    }
    return;
}

int trafik_move(radar_t *radar)
{
    actor_t *actors = radar->scenes[TRAFIK_S]->actors;

    for (; actors; actors = actors->next) {
        if (actors->type == PLANE_A) {
            PLANE(actors)->move(radar, PLANE(actors));
            radar->stat->km_flights += (PLANE(actors)->delta_t
                * PLANE(actors)->speed);
            check_landed(radar, &actors);
        }
    }
    bocollider(radar->scenes[TRAFIK_S], &radar->stat->planes_crashed, radar);
    check_medals(radar);
    return 0;
}

static void fill_with_time(char *t, int s)
{
    for (int i = 0; i < 8; i++) {
        t[i] = (i == 2 || i == 5) ? ':' : '0';
    }
    t[0] = s / 60 / 60 / 10 % 10 + '0';
    t[1] = s / 60 / 60 % 10 + '0';
    t[3] = s / 60 % 60 / 10 % 10 + '0';
    t[4] = s / 60 % 60 % 10 + '0';
    t[6] = s % 60 / 10 % 10 + '0';
    t[7] = s % 60 % 10 + '0';
    t[8] = '\0';
}

int trafik_render(radar_t *radar)
{
    actor_t *background = get_actor(radar->scenes[TRAFIK_S]->actors, "world");
    actor_t *actors = radar->scenes[TRAFIK_S]->actors;
    char t[256] = {};
    int s = sfClock_getElapsedTime(radar->scenes[TRAFIK_S]->clock)
        .microseconds / 1000 / 1000;

    ((teapot_t *) background->infos)->render(radar->window, background->infos);
    for (; actors; actors = actors->next) {
        if (actors->type == PLANE_A) {
            PLANE(actors)->render(radar, PLANE(actors));
        }
        if (actors->type == TOWER_A) {
            TOWER(actors)->render(radar, TOWER(actors));
        }
    }
    fill_with_time(t, s);
    draw_string(radar->window, t, (sfVector2f) {30, 10}, (sfVector2f) {1, 1});
    return 0;
}

int trafik_events(radar_t *radar)
{
    if (!is_plane(radar->scenes[TRAFIK_S]->actors))
        sfRenderWindow_close(radar->window);
    while (sfRenderWindow_pollEvent(radar->window, &radar->event)) {
        if (radar->event.type == sfEvtClosed)
            sfRenderWindow_close(radar->window);
        if (is_pressed(radar->event, sfKeyEscape)) {
            radar->scene_in = MENU_S;
        }
        if (is_pressed(radar->event, sfKeyL))
            radar->is_hitbox_visibles = !radar->is_hitbox_visibles;
        if (is_pressed(radar->event, sfKeyS))
            radar->is_sprite_visibles = !radar->is_sprite_visibles;
        if (is_pressed(radar->event, sfKeyRight))
            next_skin_plane(radar, radar->scenes[TRAFIK_S]->actors, 1);
        if (is_pressed(radar->event, sfKeyLeft))
            next_skin_plane(radar, radar->scenes[TRAFIK_S]->actors, -1);
    }
    return 0;
}
