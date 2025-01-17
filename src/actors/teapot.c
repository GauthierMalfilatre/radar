/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Create teapot for my_radar
*/
#include "my_radar.h"

static int teapot_render(sfRenderWindow *window, teapot_t *teapot)
{
    sfRenderWindow_drawSprite(window, teapot->sprite, 0);
    return 0;
}

teapot_t *create_teapot(sfTexture *texture, sfVector2f size, sfVector2f pos)
{
    teapot_t *new = malloc(sizeof(teapot_t));

    new->pos = pos;
    new->sprite = sfSprite_create();
    sfSprite_setTexture(new->sprite, texture, 0);
    sfSprite_setScale(new->sprite, size);
    sfSprite_setPosition(new->sprite, pos);
    new->render = &teapot_render;
    new->destroyer = &destroy_teapot;
    return new;
}

int destroy_teapot(teapot_t *teapot)
{
    sfSprite_destroy(teapot->sprite);
    free(teapot);
    return 0;
}
