/*
** EPITECH PROJECT, 2024
** MY_SHOWSTR
** File description:
** Is str showable
*/
#include "my.h"
#include <unistd.h>
#include <stdio.h>

static void my_put_hex(char c)
{
    my_putstr("\\");
    if (c < 16) {
        my_putstr("0");
    }
    my_putnbr_base((int) c, "0123456789abcdef");
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= 32 && str[i] <= 127)) {
            my_put_hex(str[i]);
        } else {
            write(1, &str[i], 1);
        }
    }
    return 0;
}
