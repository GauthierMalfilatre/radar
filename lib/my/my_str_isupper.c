/*
** EPITECH PROJECT, 2024
** MY_STR_ISLOWER
** File description:
** return 1 if is_lower
*/
#include "my.h"

static int is_upper(char str)
{
    return (str >= 'A' && str <= 'Z');
}

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_upper(str[i])) {
            return 0;
        }
    }
    return 1;
}
