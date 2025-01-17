/*
** EPITECH PROJECT, 2024
** DISP_STDARG_SUB
** File description:
** disp_stdarg_sub
*/

#include "../my_printf.h"
#include "../../my.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

static int is_valid(char c)
{
    char *chars = "-#0+ ";

    for (int i = 0; chars[i]; i++) {
        if (c == chars[i]) {
            return 1;
        }
    }
    return 0;
}

int my_print_flag_p(flaginfo_t *flaginfo, va_list list, int *sum)
{
    int newsum = 0;

    for (int i = 0; flaginfo->flags[i]; i++) {
        if (!is_valid(flaginfo->flags[i])) {
            flaginfo->flags[i] = '#';
        }
    }
    if (!is_char_in(flaginfo->flags, '#')) {
        flaginfo->flags[my_strlen(flaginfo->flags)] = '#';
        flaginfo->flags[my_strlen(flaginfo->flags) + 1] = '\0';
    }
    flaginfo->length_modifier[0] = 'l';
    flaginfo->length_modifier[1] = '\0';
    newsum += my_print_flag_x(flaginfo, list, sum);
    return newsum;
}
