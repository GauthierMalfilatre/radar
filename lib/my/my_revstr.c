/*
** EPITECH PROJECT, 2024
** MY_REVSTR
** File description:
** Rev an str
*/
#include "my.h"

static char my_cswap(char *a, char *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

char *my_revstr(char *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length / 2; i++) {
        my_cswap(&str[i], &str[length - i - 1]);
    }
    return str;
}
