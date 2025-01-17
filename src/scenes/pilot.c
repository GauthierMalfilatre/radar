/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** pilot scene related functions
*/
#include "my_radar.h"

int pilot_destroyer(scene_t *scene)
{
    destroy_actor(scene->actors);
    free(scene);
    return 0;
}

int pilot_time(radar_t *radar)
{
    trafik_time(radar);
    return 0;
}

int pilot_move(radar_t *radar)
{
    return 0;
}

static void make_a_little_couch(sfRenderWindow *win)
{
    sfRectangleShape *overlay = sfRectangleShape_create();

    sfRectangleShape_setSize(overlay, (sfVector2f){1920, 1080});
    sfRectangleShape_setFillColor(overlay, sfColor_fromRGBA(0, 0, 0, 128));
    sfRenderWindow_drawRectangleShape(win, overlay, NULL);
    sfRectangleShape_destroy(overlay);
    return;
}

static void draw_line(radar_t *radar, int offset)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, sfYellow);
    sfRectangleShape_setPosition(rect, (sfVector2f){offset, 440 + 4});
    sfRectangleShape_setSize(rect, (sfVector2f){radar->stat->km_flights
        * 300 / 10000000, 200 - 8});
    sfRenderWindow_drawRectangleShape(radar->window, rect, 0);
    for (int i = 1; i < radar->stat->km_flights / 10000000; i++) {
        if (offset + 300 * i - 36 < 0) {
            continue;
        }
        sfRectangleShape_setSize(rect, (sfVector2f){72, 72});
        sfRectangleShape_setPosition(rect, (sfVector2f)
            {offset + 300 * i - 36, 354});
        sfRenderWindow_drawRectangleShape(radar->window, rect, 0);
    }
    sfRectangleShape_destroy(rect);
}

static void draw_pilotpass(radar_t *radar, int offset)
{
    int x = 300 - 30;
    sfSprite *skin = TEAPOT(get_actor(radar->scenes[PILOT_S]->actors,
        "skin"))->sprite;

    sfSprite_setTexture(skin, get_texture(radar->textures, "pass"), 1);
    sfSprite_setScale(skin, (sfVector2f){1, 1});
    sfSprite_setPosition(skin, (sfVector2f){0, 0});
    sfRenderWindow_drawSprite(radar->window, skin, 0);
    draw_line(radar, offset);
    for (skins_t *temp = radar->skin; temp; temp = temp->next) {
        if (offset + x < 0) {
            x += 300;
            continue;
        }
        sfSprite_setTexture(skin, temp->texture, 1);
        sfSprite_setPosition(skin, (sfVector2f) {offset + x, 350 + 15});
        sfSprite_setScale(skin, (sfVector2f){3, 3});
        sfRenderWindow_drawSprite(radar->window, skin, 0);
        x += 300;
    }
}

int pilot_render(radar_t *radar)
{
    trafik_render(radar);
    make_a_little_couch(radar->window);
    draw_pilotpass(radar, radar->scenes[PILOT_S]->offset);
    draw_string(radar->window, "Pilot pass level: ", V2F(20, 250), V2F(2, 2));
    draw_int(radar, radar->stat->km_flights / 10000000, V2F(220 * 2, 250),
        V2F(2, 2));
    draw_string(radar->window, "Launched: ", V2F(20, 660), V2F(1, 1));
    draw_int(radar, radar->stat->planes_launched, V2F(170, 660), V2F(1, 1));
    draw_string(radar->window, "Landed: ", V2F(20, 710), V2F(1, 1));
    draw_int(radar, radar->stat->planes_landed, V2F(170, 710), V2F(1, 1));
    draw_string(radar->window, "Crashed: ", V2F(20, 760), V2F(1, 1));
    draw_int(radar, radar->stat->planes_crashed, V2F(170, 760), V2F(1, 1));
    return 0;
}

static int len_all(skins_t *skins)
{
    int len = 0;

    for (skins_t *temp = skins; temp; temp = temp->next) {
        len += 300;
    }
    return len - 1;
}

static void process_scroll(radar_t *radar)
{
    float offset = (radar->event.mouseWheelScroll.delta) * 10;

    if (offset < 0 && radar->scenes[PILOT_S]->offset -
        300 + len_all(radar->skin) >= 6 * 300) {
        radar->scenes[PILOT_S]->offset -= 300;
    }
    if (offset > 0 && radar->scenes[PILOT_S]->offset + 300 <= 0) {
        radar->scenes[PILOT_S]->offset += 300;
    }
}

int pilot_events(radar_t *radar)
{
    while (sfRenderWindow_pollEvent(radar->window, &radar->event)) {
        if (radar->event.type == sfEvtClosed) {
            sfRenderWindow_close(radar->window);
        }
        if (is_pressed(radar->event, sfKeyEscape)) {
            radar->scene_in = MENU_S;
        }
        if (radar->event.type == sfEvtMouseWheelScrolled) {
            process_scroll(radar);
        }
    }
    return 0;
}
