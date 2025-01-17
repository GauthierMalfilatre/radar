/*
** EPITECH PROJECT, 2024
** FLAG_I
** File description:
** Deal with flag i
*/
#include "../my_printf.h"
#include "../../my.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

static int flag_o_sub(flaginfo_t *flaginfo, long long int nb)
{
    int nb_len = my_nbrlen(nb, 8);
    int newsum = 0;

    if (is_char_in(flaginfo->flags, '#') && nb &&
        flaginfo->precision < nb_len) {
        flaginfo->precision = nb_len + 1;
    }
    if (flaginfo->precision != -1 && flaginfo->precision > nb_len) {
        flaginfo->width -= flaginfo->precision - nb_len;
    }
    newsum += add_width(flaginfo, nb_len, 0, nb);
    for (int i = 0; i < flaginfo->precision - nb_len; i++) {
        newsum += my_putchar('0');
    }
    newsum += my_putnbr_base_ull(nb, "01234567");
    newsum += add_width(flaginfo, nb_len, 1, nb);
    return newsum;
}

int my_print_flag_o(flaginfo_t *flaginfo, va_list list, int *sum)
{
    long long int nb = va_arg(list, long long int);

    switch (flaginfo->length_modifier[0]) {
        case 'l':
            if (flaginfo->length_modifier[1] == 'l')
                nb = (unsigned long long int) nb;
                break;
            nb = (unsigned long int) nb;
            break;
        case 'h':
            if (flaginfo->length_modifier[1] == 'h')
                nb = (unsigned char) nb;
                break;
            nb = (unsigned short int) nb;
            break;
        default:
            nb = (unsigned int) nb;
            break;
    }
    return flag_o_sub(flaginfo, nb);
}
