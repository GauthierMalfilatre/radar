/*
** EPITECH PROJECT, 2024
** MY_STRUPCASE
** File description:
** Put every letter in str
*/
#include "my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
    }
    return str;
}
