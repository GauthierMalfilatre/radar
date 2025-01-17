/*
** EPITECH PROJECT, 2024
** IS_NAN
** File description:
** Ethan.
*/
#include "../my_printf.h"
#include "../../my.h"

char *get_weird(long double a)
{
    if (a != a) {
        return a >= 0 ? "nan" : "-nan";
    }
    if (a == a && a == a + 1) {
        return a > 0 ? "inf" : "-inf";
    }
    return 0;
}
