/*
** EPITECH PROJECT, 2024
** MY_STRCAT
** File description:
** Cat 2 str
*/
#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int length = my_strlen(dest);
    int i = 0;

    for (; src[i] != '\0' && i < nb; i++) {
        dest[length + i] = src[i];
    }
    dest[length + i] = '\0';
    return dest;
}
