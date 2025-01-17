/*
** EPITECH PROJECT, 2024
** MY_FIND_PRIME_SUP
** File description:
** Find the first prime number greater than of equal to the gave number
*/
#include "my.h"

int my_find_prime_sup(int nb)
{
    int javascriptsucks = 1;

    for (int i = nb; javascriptsucks; i++) {
        if (my_is_prime(i)) {
            return i;
        }
    }
}
