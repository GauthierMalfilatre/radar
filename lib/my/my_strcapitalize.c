/*
** EPITECH PROJECT, 2024
** MY_STRCAPITALIZE
** File description:
** Tests Capitalize letters
*/
#include "my.h"
#include <stdlib.h>

static int is_digit(char str)
{
    return (str >= '0' && str <= '9');
}

static int is_lower(char str)
{
    return (str >= 'a' && str <= 'z');
}

static int is_upper(char str)
{
    return (str >= 'A' && str <= 'Z');
}

static int is_alpha(char str)
{
    return is_lower(str) || is_upper(str);
}

char *my_strcapitalize(char *str)
{
    my_strlowcase(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if ((!i && is_lower(str[i])) || (i && !is_digit(str[i - 1])
            && is_lower(str[i]) && !is_alpha(str[i - 1]))) {
            str[i] -= 32;
            continue;
        }
        str[i] += (is_upper(str[i])) ? 32 : 0;
    }
    return str;
}

char *my_strupper(char const *str)
{
    char *kronk_buffer = malloc(my_strlen(str) + 1);

    for (int i = 0; str[i]; i++) {
        if (is_lower(str[i])) {
            kronk_buffer[i] = str[i] + ('A' - 'a');
            continue;
        }
        kronk_buffer[i] = str[i];
    }
    return kronk_buffer;
}
