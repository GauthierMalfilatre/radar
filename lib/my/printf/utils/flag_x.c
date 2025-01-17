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

static int flag_x_sub(flaginfo_t *flaginfo, unsigned long long int nb,
    char *base)
{
    int is_hash_in = is_char_in(flaginfo->flags, '#');
    int nb_len = my_nbrlen_ull(nb, 16);
    int newsum = 0;

    flaginfo->width -= 2 * is_hash_in;
    if (flaginfo->precision != -1 && flaginfo->precision > nb_len)
        flaginfo->width -= flaginfo->precision - nb_len;
    if (is_char_in(flaginfo->flags, '0') && is_hash_in && nb != 0) {
        newsum += my_putchar('0') + my_putchar(base[14] == 'E' ? 'X' : 'x');
    }
    newsum += add_width(flaginfo, nb_len, 0, nb);
    if (!is_char_in(flaginfo->flags, '0') && is_hash_in && nb != 0) {
        newsum += my_putchar('0') + my_putchar(base[14] == 'E' ? 'X' : 'x');
    }
    for (int i = 0; i < flaginfo->precision - nb_len; i++) {
        newsum += my_putchar('0');
    }
    newsum += my_putnbr_base_ull(nb, base);
    newsum += add_width(flaginfo, nb_len, 1, nb);
    return newsum;
}

static int st_my_print_flag_x(flaginfo_t *flaginfo, va_list list, int *sum,
    char *base)
{
    unsigned long long int nb = va_arg(list, unsigned long long int);

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
    return flag_x_sub(flaginfo, nb, base);
}

int my_print_flag_x(flaginfo_t *flaginfo, va_list list, int *sum)
{
    if (flaginfo->conversion == 'X') {
        return st_my_print_flag_x(flaginfo, list, sum, "0123456789ABCDEF");
    }
    return st_my_print_flag_x(flaginfo, list, sum, "0123456789abcdef");
}
