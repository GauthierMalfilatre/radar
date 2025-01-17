/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Utils functions for my_radar
*/
#include "my_radar.h"

char *int_to_str(int n)
{
    int size = my_nbrlen(n, 10);
    char *str = malloc(size + 1);
    int i = 0;

    if (size == 1) {
        str[0] = n + '0';
    if (size < 0) {
        size = -size;
        str[i] = '-';
        ++i;
    }
    } else {
        for (; n > 0; ++i) {
            str[i] = n % 10 + '0';
            n /= 10;
        }
    }
    str[size] = '\0';
    my_revstr(str);
    return str;
}

double get_bnorme(sfVector2f pos1, sfVector2f pos2)
{
    double norme1 = get_norme(pos1, pos2);
    double n2 = get_norme(pos1, (sfVector2f) {pos2.x - WIN_W, pos2.y - WIN_H});

    if (norme1 < norme1) {
        return get_norme(pos1, pos2);
    }
    return norme1;
}

void draw_int(radar_t *radar, int n, sfVector2f pos, sfVector2f scale)
{
    char *str = int_to_str(n);

    draw_string(radar->window, str, pos, scale);
    free(str);
}
