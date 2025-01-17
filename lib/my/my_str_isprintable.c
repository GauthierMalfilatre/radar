/*
** EPITECH PROJECT, 2024
** MY_STR_ISPRINTABLE
** File description:
** Check if str is printable
*/
#include "my.h"

static int is_printable(char str)
{
    return str >= 32;
}

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_printable(str[i])) {
            return 0;
        }
    }
    return 1;
}
