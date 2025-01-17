/*
** EPITECH PROJECT, 2024
** CONVERT_BASE
** File description:
** Convert base to base
*/
#include "my.h"
#include <stdlib.h>

static char *subfonction(char *dest, int nb, char const *base_to, int diviser)
{
    int i = 0;

    if (nb < 0) {
        nb *= -1;
        dest[i] = '-';
        i++;
    }
    for (; nb > 0; i++) {
        dest[i] = base_to[nb % diviser];
        nb /= diviser;
    }
    dest[i] = '\0';
    return dest;
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    long nb = my_getnbr_base(nbr, base_from);
    int diviser = my_strlen(base_to);
    int size = my_nbrlen(nb, diviser);
    char *dest = malloc(size + 2);

    if (nb == 0) {
        dest[0] = base_to[0];
        dest[1] = '\0';
        return dest;
    }
    subfonction(dest, nb, base_to, diviser);
    if (dest[0] == '-') {
        my_revstr(dest + 1);
    } else {
        my_revstr(dest);
    }
    return dest;
}
