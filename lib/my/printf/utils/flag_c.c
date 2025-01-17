/*
** EPITECH PROJECT, 2024
** FLAG_C
** File description:
** Deal with c conversion specifier
*/
#include "../my_printf.h"
#include "../../my.h"
#include <stdarg.h>
#include <unistd.h>

int my_print_flag_c(flaginfo_t *flaginfo, va_list list, int *sum)
{
    int newsum = add_width(flaginfo, 1, 0, 0);

    if (!is_char_in(flaginfo->flags, 'l')) {
        my_putchar(va_arg(list, int));
    }
    newsum += add_width(flaginfo, 1, 1, 0);
    return newsum + 1;
}
