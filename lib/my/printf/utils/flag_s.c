/*
** EPITECH PROJECT, 2024
** FLAG_S
** File description:
** Deal with s conversion specifier
*/
#include "../my_printf.h"
#include "../../my.h"
#include <stdarg.h>
#include <unistd.h>

int my_print_flag_s(flaginfo_t *flaginfo, va_list list, int *sum)
{
    int newsum = 0;
    char *kronk_buffer = va_arg(list, char *);

    newsum += add_width(flaginfo, my_strnlen(kronk_buffer,
        flaginfo->precision), 0, 0);
    newsum += my_putnstr(kronk_buffer, flaginfo->precision);
    newsum += add_width(flaginfo, my_strnlen(kronk_buffer,
        flaginfo->precision), 1, 0);
    return newsum;
}
