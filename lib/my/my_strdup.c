/*
** EPITECH PROJECT, 2024
** MY_STRRDUP
** File description:
** Duplicate a str
*/
#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    my_strcpy(dest, src);
    dest[my_strlen(src)] = '\0';
    return dest;
}

char *my_strndup(char const *src, int n)
{
    char *dest;

    if (n > my_strlen(src))
        return 0;
    dest = malloc(n + 1);
    my_strncpy(dest, src, n);
    dest[n] = '\0';
    return dest;
}
