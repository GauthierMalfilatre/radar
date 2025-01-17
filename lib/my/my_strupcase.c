/*
** EPITECH PROJECT, 2024
** MY_STRUPCASE
** File description:
** Put every letter in str
*/
#include "my.h"

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] -= 32;
        }
    }
    return str;
}
