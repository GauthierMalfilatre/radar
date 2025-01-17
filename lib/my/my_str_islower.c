/*
** EPITECH PROJECT, 2024
** MY_STR_ISLOWER
** File description:
** return 1 if is_lower
*/
#include "my.h"

static int is_lower(char str)
{
    return (str >= 'a' && str <= 'z');
}

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_lower(str[i])) {
            return 0;
        }
    }
    return 1;
}
