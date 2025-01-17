/*
** EPITECH PROJECT, 2024
** MY_STR_ISALPHA
** File description:
** return 1 if is_alpha
*/
#include "my.h"

static int is_alpha(char str)
{
    return (str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z');
}

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_alpha(str[i])) {
            return 0;
        }
    }
    return 1;
}
