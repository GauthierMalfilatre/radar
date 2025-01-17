/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Menu scene related functions
*/
#include "my_radar.h"

static void redirect_mouse(radar_t *radar)
{
    sfVector2i pos = {radar->event.mouseButton.x, radar->event.mouseButton.y};

    if (pos.x > 1430 && pos.x < 1720 && pos.y > 265 && pos.y < 310)
        radar->scene_in = TRAFIK_S;
    if (pos.x > 1430 && pos.x < 1770 && pos.y > 415 && pos.y < 452)
        radar->scene_in = PILOT_S;
    if (pos.x > 1430 && pos.x < 1700 && pos.y > 560 && pos.y < 600)
        radar->scene_in = MEDALS_S;
    if (pos.x > 1430 && pos.x < 1730 && pos.y > 706 && pos.y < 744)
        return;
    if (pos.x > 1430 && pos.x < 1600 && pos.y > 852 && pos.y < 894)
        sfRenderWindow_close(radar->window);
    return;
}

static void draw_at_mouse(radar_t *radar)
{
    sfVector2i pos = sfMouse_getPosition((sfWindow *) radar->window);
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rectangle, sfColor_fromRGBA(0, 0, 0, 128));
    sfRectangleShape_setSize(rectangle, (sfVector2f) {400, 70});
    sfRectangleShape_setPosition(rectangle, (sfVector2f) {-10000, - 100000});
    if (pos.x > 1430 && pos.x < 1720 && pos.y > 265 && pos.y < 310)
        sfRectangleShape_setPosition(rectangle, (sfVector2f) {1420, 255});
    if (pos.x > 1430 && pos.x < 1770 && pos.y > 415 && pos.y < 452)
        sfRectangleShape_setPosition(rectangle, (sfVector2f) {1420, 405});
    if (pos.x > 1430 && pos.x < 1700 && pos.y > 560 && pos.y < 600)
        sfRectangleShape_setPosition(rectangle, (sfVector2f) {1420, 550});
    if (pos.x > 1430 && pos.x < 1730 && pos.y > 706 && pos.y < 744)
        sfRectangleShape_setPosition(rectangle, (sfVector2f) {1420, 696});
    if (pos.x > 1430 && pos.x < 1600 && pos.y > 852 && pos.y < 894)
        sfRectangleShape_setPosition(rectangle, (sfVector2f) {1420, 842});
    sfRenderWindow_drawRectangleShape(radar->window, rectangle, 0);
    sfRectangleShape_destroy(rectangle);
    return;
}

static void destroy_sprites(actor_t *actor)
{
    if (actor->next)
        destroy_sprites(actor->next);
    switch (actor->type) {
        case PLANE_A:
            ((plane_t *) actor->infos)->destroyer((plane_t *) actor->infos);
            break;
        case TOWER_A:
            ((tower_t *) actor->infos)->destroyer((tower_t *) actor->infos);
            break;
        default:
            sfSprite_destroy(((teapot_t *) actor->infos)->sprite);
            break;
    }
    free(actor->infos);
    free(actor->name);
    free(actor);
    return;
}

int menu_destroyer(scene_t *scene)
{
    destroy_sprites(scene->actors);
    free(scene);
    return 0;
}

int menu_time(radar_t *radar)
{
    trafik_time(radar);
    return 0;
}

int menu_move(radar_t *radar)
{
    return 0;
}

// As a background, we can just draw planes, towers, and map.
int menu_render(radar_t *radar)
{
    sfRectangleShape *overlay = sfRectangleShape_create();
    char *km = int_to_str(radar->stat->km_flights);

    trafik_render(radar);
    sfRectangleShape_setSize(overlay, (sfVector2f){1920, 1080});
    sfRectangleShape_setFillColor(overlay, sfColor_fromRGBA(0, 0, 0, 128));
    sfRenderWindow_drawRectangleShape(radar->window, overlay, NULL);
    sfRenderWindow_drawSprite(radar->window, ((teapot_t *)
        get_actor(radar->scenes[MENU_S]->actors, "menu_1")->infos)->sprite, 0);
    draw_at_mouse(radar);
    draw_string(radar->window, "Guest - Km flights: ", (sfVector2f){1400, 200},
        (sfVector2f) {0.8f, 0.8f});
    draw_string(radar->window, km, (sfVector2f){1600, 200},
        (sfVector2f) {0.8f, 0.8f});
    free(km);
    sfRectangleShape_destroy(overlay);
    return 0;
}

int menu_events(radar_t *radar)
{
    while (sfRenderWindow_pollEvent(radar->window, &radar->event)) {
        if (radar->event.type == sfEvtClosed) {
            sfRenderWindow_close(radar->window);
        }
        if (radar->event.type == sfEvtMouseButtonPressed) {
            redirect_mouse(radar);
        }
        if (is_pressed(radar->event, sfKeyEscape)) {
            radar->scene_in = TRAFIK_S;
        }
    }
    return 0;
}
