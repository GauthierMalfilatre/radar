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

/*
** The 0 flag padds nuber with 0 instead of spaces,
** but precision overrides the 0 flag and :
** -> number is padded with 0 matching precision
** -> number padded with precision is re-padded matching width
**    with spaces, even if it's a 0 flag.
*/

// I guess %zi, %ti && %ji worked.

static int flag_i_sub(flaginfo_t *flaginfo, long long int nb)
{
    int newsum = 0;
    int nb_len = my_nbrlen(nb, 10);

    if (flaginfo->precision != -1 && flaginfo->precision > nb_len) {
        flaginfo->width -= flaginfo->precision - nb_len;
    }
    newsum += add_width(flaginfo, nb_len, 0, nb);
    for (int i = 0; i < flaginfo->precision - nb_len; i++) {
        newsum += my_putchar('0');
    }
    newsum += my_putnbr_ll(ABS(nb));
    newsum += add_width(flaginfo, nb_len, 1, nb);
    return newsum;
}

int my_print_flag_i(flaginfo_t *flaginfo, va_list list, int *sum)
{
    long long int nb = va_arg(list, long long int);
    int nb_len;

    switch (flaginfo->length_modifier[0]) {
        case 'l':
            if (flaginfo->length_modifier[1] == 'l')
                break;
            nb = (long int) nb;
            break;
        case 'h':
            if (flaginfo->length_modifier[1] == 'h')
                nb = (char) nb;
                break;
            nb = (short int) nb;
            break;
        case '\0':
            nb = (int) nb;
            break;
    }
    return flag_i_sub(flaginfo, nb);
}
