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

int is_char_in(char *flags, char c)
{
    for (int i = 0; flags[i]; i++) {
        if (flags[i] == c) {
            return 1;
        }
    }
    return 0;
}

static int is_valid(flaginfo_t *flaginfo)
{
    char *chars = "ideEfF";

    for (int i = 0; chars[i]; i++) {
        if (flaginfo->conversion == chars[i]) {
            return 1;
        }
    }
    return 0;
}

static int add_width_sub_1(flaginfo_t *flag, int *newsum, int is_last,
    long long int nb)
{
    if ((is_char_in(flag->flags, '+') || is_char_in(flag->flags, ' ') ||
        nb < 0) && is_char_in(flag->flags, '0') && !is_last && is_valid(flag))
        if (is_char_in(flag->flags, ' ') && nb > 0)
            (*newsum) += my_putchar(' ');
        else
            (*newsum) += my_putchar(nb >= 0 ? '+' : '-');
        return (nb >= 0 && (is_char_in(flag->flags, '+') ||
            is_char_in(flag->flags, ' ')) && is_valid(flag));
    return 0;
}

static int add_width_sub_2(flaginfo_t *flag, int *newsum, int is_last,
    long long int nb)
{
    if ((is_char_in(flag->flags, '+') || is_char_in(flag->flags, ' ') ||
        nb < 0) && !is_char_in(flag->flags, '0') && !is_last && is_valid(flag))
        if (is_char_in(flag->flags, ' ') && nb > 0)
            (*newsum) += my_putchar(' ');
        else
            (*newsum) += my_putchar(nb >= 0 ? '+' : '-');
    return 0;
}

int add_width(flaginfo_t *flag, int len, int is_last, long long int nb)
{
    int newsum = 0;
    int is_lpadded = is_char_in(flag->flags, '-');
    int missing_width = flag->width - len;

    missing_width -= add_width_sub_1(flag, &newsum, is_last, nb);
    for (int j = 0; j < missing_width && is_last == is_lpadded; j++) {
        newsum += my_putchar((is_char_in(flag->flags, '0')
            && !is_lpadded && flag->precision < len) ? '0' : ' ');
    }
    add_width_sub_2(flag, &newsum, is_last, nb);
    return newsum;
}
