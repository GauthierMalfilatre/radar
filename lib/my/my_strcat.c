/*
** EPITECH PROJECT, 2024
** MY_STRCAT
** File description:
** Cat 2 str
*/
#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int length = my_strlen(dest);
    int i = 0;

    for (; src[i]; i++) {
        dest[length + i] = src[i];
    }
    dest[length + i] = '\0';
    return dest;
}

char *my_strccat(char *dest, char const c)
{
    int length = my_strlen(dest);

    dest[length] = c;
    dest[length + 1] = '\0';
    return dest;
}

char *my_stradd(char *dest, char *src)
{
    char *new = malloc(my_strlen(dest) + my_strlen(src) + 1);

    my_strcpy(new, dest);
    my_strcat(new, src);
    return new;
}
