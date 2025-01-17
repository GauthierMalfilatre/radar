/*
** EPITECH PROJECT, 2024
** MY_IS_PRIME
** File description:
** Find if is prime
*/
#include "my.h"

int my_is_prime(int nb)
{
    if (nb < 2) {
        return 0;
    } else if (nb == 4) {
        return 0;
    }
    for (int i = 2; i < nb / 2; i++) {
        if (!(nb % i)) {
            return 0;
        }
    }
    return 1;
}
