/*
** EPITECH PROJECT, 2024
** MY_GETNBR_BASE
** File description:
** Get numbers
*/
#include "my.h"

int get_str_index(char **kronk_list, char *kronk_buffer)
{
    int i = 0;

    for (; my_strcmp(kronk_list[i], kronk_buffer); i++);
    return i;
}

int get_index(char const *str, char c)
{
    int i = 0;

    for (; str[i]; i++) {
        if (str[i] == c) {
            return i;
        }
    }
    return 0;
}
