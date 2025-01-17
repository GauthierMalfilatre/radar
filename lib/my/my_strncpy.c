/*
** EPITECH PROJECT, 2024
** MY_STRNCPY
** File description:
** Copy n char of a string
*/
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
        if (src[i] == '\0') {
            break;
        }
    }
    dest[n] = '\0';
    return dest;
}
