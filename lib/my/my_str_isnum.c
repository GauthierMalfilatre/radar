/*
** EPITECH PROJECT, 2024
** MY_STR_ISALPHA
** File description:
** return 1 if is_alpha
*/
#include "my.h"

static int is_num(char str)
{
    return (str >= '0' && str <= '9');
}

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_num(str[i]) && str[i] != '.') {
            return 0;
        }
    }
    return 1;
}
