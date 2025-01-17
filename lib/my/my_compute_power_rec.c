/*
** EPITECH PROJECT, 2024
** MY_COMPUTE_POWER_REC
** File description:
** Tiny recursive power calculator - kinda ez
*/
#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        return 1;
    }
    if (p < 0 || (nb == 2 && p >= 31)) {
        return 0;
    }
    return nb * my_compute_power_rec(nb, p - 1);
}
