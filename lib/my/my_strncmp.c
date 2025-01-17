/*
** EPITECH PROJECT, 2024
** MY_STRCNP
** File description:
** Compare two strings to n
*/
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; i < n; i++) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        if (!s1[i] || !s2[i]) {
            break;
        }
    }
    return 0;
}
