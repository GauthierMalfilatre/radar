/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Utils functions for my_radar
*/
#include "my_radar.h"

sfVector2f fvectmul(sfVector2f vector, double mul1, double mul2)
{
    return (sfVector2f) {vector.x * mul1, vector.y * mul2};
}

sfVector2f get_dir(sfVector2f pos1, sfVector2f pos2, double speed)
{
    sfVector2f vect = (sfVector2f) {pos2.x - pos1.x, pos2.y - pos1.y};
    double norme = sqrt(pow(vect.x, 2) + pow(vect.y, 2));

    vect.x = vect.x / norme * speed;
    vect.y = vect.y / norme * speed;
    return vect;
}

double get_norme(sfVector2f pos1, sfVector2f pos2)
{
    sfVector2f vect = (sfVector2f) {pos2.x - pos1.x, pos2.y - pos1.y};

    return sqrt(pow(vect.x, 2) + pow(vect.y, 2));
}

int is_pressed(sfEvent evt, int key)
{
    return evt.type == sfEvtKeyPressed && evt.key.code == key;
}

void draw_string(sfRenderWindow *window, char *str, sfVector2f pos,
    sfVector2f size)
{
    sfFont *font = sfFont_createFromFile(FP("airstrip.ttf"));
    sfText *text = sfText_create();

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setScale(text, size);
    sfRenderWindow_drawText(window, text, sfFalse);
    sfFont_destroy(font);
    sfText_destroy(text);
    return;
}
