/*
** EPITECH PROJECT, 2024
** MY_COMPUTE_SQUARE_ROOT
** File description:
** Square root calculator - kinda ez
*/
#include "my.h"

int my_compute_square_root(int nb)
{
    for (int i = 0; i < nb + 1; i++) {
        if (my_compute_power_rec(i, 2) == nb) {
            return i;
        }
    }
    return 0;
}
