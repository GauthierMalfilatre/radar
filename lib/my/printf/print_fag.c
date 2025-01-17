/*
** EPITECH PROJECT, 2024
** PRINTF_FLAG
** File description:
** Print a fag.
*/

#include "../my.h"
#include "my_printf.h"
#include <stdarg.h>

func_pointers_t const POINTERS[] = {
    {'%', &my_print_flag_percent},
    {'c', &my_print_flag_c},
    {'s', &my_print_flag_s},
    {'i', &my_print_flag_i},
    {'d', &my_print_flag_i},
    {'n', &my_print_flag_n},
    {'x', &my_print_flag_x},
    {'X', &my_print_flag_x},
    {'u', &my_print_flag_u},
    {'o', &my_print_flag_o},
    {'p', &my_print_flag_p},
    {'f', &my_print_flag_f},
    {'F', &my_print_flag_capsf},
    {'e', &my_print_flag_e},
    {'E', &my_print_flag_capse},
    {'a', &my_print_flag_a},
    {'A', &my_print_flag_capsa},
    {'g', &my_print_flag_g},
    {'G', &my_print_flag_capsg},
    {'\0', 0}
};

void printf_ag(const flaginfo_t *flaginfo, va_list argv, int *sum)
{
    if (!(flaginfo->conversion)) {
        *sum += my_putstr(flaginfo->flags);
        return;
    }
    for (int i = 0; POINTERS[i].chr; i++) {
        if (POINTERS[i].chr == flaginfo->conversion) {
            *sum += POINTERS[i].pointfn(flaginfo, argv, sum);
        }
    }
    return;
}
