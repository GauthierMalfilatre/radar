/*
** EPITECH PROJECT, 2024
** MY_ISNEG
** File description:
** N if negative P if positive
*/
#include "my.h"

int my_isneg(int n)
{
    int p = (n < 0) ? 'N' : 'P';

    my_putchar(p);
    return 0;
}
