/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** medals scene related functions
*/
#include "my_radar.h"

int medals_destroyer(scene_t *scene)
{
    free(scene);
    return 0;
}

int medals_time(radar_t *radar)
{
    trafik_time(radar);
    return 0;
}

int medals_move(radar_t *radar)
{
    return 0;
}

static void display_medals(sfRenderWindow *win, medals_t *medals, int y)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    int count = 0;

    sfRectangleShape_setSize(rect, (sfVector2f) {800, 100});
    for (medals_t *temp = medals; temp; temp = temp->next) {
        if (temp->is_checked) {
            sfRectangleShape_setFillColor(rect, sfColor_fromRGB(10, 35, 102));
        } else {
            sfRectangleShape_setFillColor(rect,
                sfColor_fromRGBA(0, 25, 92, 128));
        }
        sfRectangleShape_setPosition(rect, (sfVector2f){560, y + count * 140});
        sfRenderWindow_drawRectangleShape(win, rect, 0);
        draw_string(win, temp->name, (sfVector2f) {960 - my_strlen(temp->name)
            * 7, y + count * 140 + 10}, (sfVector2f) {1.f, 1.f});
        draw_string(win, temp->description, (sfVector2f) {750, y + count * 140
            + 50}, (sfVector2f) {1.f, 1.f});
        count++;
    }
    sfRectangleShape_destroy(rect);
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

int medals_render(radar_t *radar)
{
    trafik_render(radar);
    make_a_little_couch(radar->window);
    display_medals(radar->window, radar->medals,
        20 + radar->scenes[MEDALS_S]->offset);
    return 0;
}

static int all_len(medals_t *medals)
{
    int len = 10;

    for (medals_t *temp = medals; temp; temp = temp->next) {
        len += 140;
    }
    return len;
}

static void process_scroll(radar_t *radar)
{
    float offset = (radar->event.mouseWheelScroll.delta) * 10;

    if (offset > 0 && radar->scenes[MEDALS_S]->offset + offset <= 0) {
        radar->scenes[MEDALS_S]->offset += offset;
    }
    if (offset < 0 && radar->scenes[MEDALS_S]->offset +
        offset + all_len(radar->medals) > WIN_H) {
        radar->scenes[MEDALS_S]->offset += offset;
    }
}

int medals_events(radar_t *radar)
{
    while (sfRenderWindow_pollEvent(radar->window, &radar->event)) {
        if (radar->event.type == sfEvtClosed) {
            sfRenderWindow_close(radar->window);
        }
        if (is_pressed(radar->event, sfKeyEscape)) {
            radar->scene_in = MENU_S;
            return 0;
        }
        if (radar->event.type == sfEvtMouseWheelScrolled) {
            process_scroll(radar);
        }
    }
    return 0;
}
