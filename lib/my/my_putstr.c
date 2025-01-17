/*
** EPITECH PROJECT, 2024
** MY_PUTSTR
** File description:
** Displays a string
*/
#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    return write(1, str, my_strlen(str));
}

int my_putnstr(char const *str, int n)
{
    int i = 0;

    if (n == -1) {
        n = my_strlen(str);
    }
    for (; str[i] && i < n; i++) {
        my_putchar(str[i]);
    }
    return i;
}

int my_strnlen(char const *str, int n)
{
    int i = 0;

    if (n == -1) {
        n = my_strlen(str);
    }
    for (; str[i] && (i < n); i++);
    return i;
}

int my_errstr(char const *str)
{
    for (int i = 0; str[i]; i++) {
        write(2, &str[i], 1);
    }
    return -1;
}
