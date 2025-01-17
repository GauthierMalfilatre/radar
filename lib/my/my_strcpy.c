/*
** EPITECH PROJECT, 2024
** MY_STRCPY
** File description:
** Copy a string into another
*/
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; i < my_strlen(src); i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
