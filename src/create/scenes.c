/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Create scenes
*/
#include "my_radar.h"

scene_t *create_trafik(radar_t *radar, char *file)
{
    scene_t *new = malloc(sizeof(scene_t));

    new->actors = load_trafik_actors(radar->textures, file);
    if (!new->actors) {
        free(new);
        return 0;
    }
    new->clock = sfClock_create();
    new->timer = &trafik_time;
    new->mover = &trafik_move;
    new->render = &trafik_render;
    new->events = &trafik_events;
    new->destroyer = &trafik_destroyer;
    return new;
}

scene_t *create_menu(radar_t *radar)
{
    scene_t *new = malloc(sizeof(scene_t));

    new->timer = &menu_time;
    new->mover = &menu_move;
    new->render = &menu_render;
    new->events = &menu_events;
    new->destroyer = &menu_destroyer;
    new->actors = load_menu_actors(radar->textures);
    return new;
}

scene_t *create_medalss(radar_t *radar)
{
    scene_t *new = malloc(sizeof(scene_t));

    new->timer = &medals_time;
    new->mover = &medals_move;
    new->render = &medals_render;
    new->events = &medals_events;
    new->destroyer = &medals_destroyer;
    new->offset = 0;
    new->actors = load_medals_actors(radar->textures);
    return new;
}

scene_t *create_pilot(radar_t *radar)
{
    scene_t *new = malloc(sizeof(scene_t));

    new->timer = &pilot_time;
    new->mover = &pilot_move;
    new->render = &pilot_render;
    new->events = &pilot_events;
    new->destroyer = &pilot_destroyer;
    new->offset = 0;
    new->actors = load_pilot_actors(radar->textures);
    return new;
}
