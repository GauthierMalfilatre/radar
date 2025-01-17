/*
** EPITECH PROJECT, 2024
** MY_STRLEN
** File description:
** Returns the size of an integer
*/
#include "my.h"

int my_strlen(char const *str)
{
    int length = 0;

    for (char const *i = str; *i != '\0'; i++) {
        length++;
    }
    return length;
}
