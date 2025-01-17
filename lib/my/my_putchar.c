/*
** EPITECH PROJECT, 2024
** MY_PUTCHAR
** File description:
** Put a char
*/
#include "my.h"
#include <unistd.h>

int my_putchar(char c)
{
    return write(1, &c, 1);
}
