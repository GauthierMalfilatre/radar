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
#include <stdlib.h>

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
#include <stdlib.h>

static int my_ps(long double f, flaginfo_t *flaginfo)
{
    return my_put_science(f, flaginfo->precision, flaginfo->conversion == 'E');
}

static int flag_e_sub_sub(flaginfo_t *flaginfo, double nb_d,
    long double nb_ld, int newsum)
{
    int is_long = is_char_in(flaginfo->length_modifier, 'L');
    int is_alt = is_char_in(flaginfo->flags, '#') && flaginfo->precision == 0;
    char *is_nan = get_weird(is_long ? nb_ld : nb_d);
    int nb_len = my_flen(ABS(is_long ? nb_ld : nb_d), flaginfo->precision);

    if (is_nan) {
        nb_len = my_strlen(is_nan);
        nb_d = 0;
        nb_ld = 0;
    }
    if (is_long)
        newsum += add_width(flaginfo, nb_len, 0, nb_ld < 0 ? -1 : 1);
    else
        newsum += add_width(flaginfo, nb_len, 0, nb_d < 0 ? -1 : 1);
    if (is_nan)
        newsum += my_putstr(is_nan);
    else
        newsum += my_ps(ABS(is_long ? nb_ld : nb_d), flaginfo);
    newsum += is_alt ? my_putchar('.') : 0;
    return newsum + add_width(flaginfo, nb_len, 1, is_long ? nb_ld : nb_d);
}

static int flag_e_sub(flaginfo_t *flaginfo, double nb_d,
    long double nb_ld, int *sum)
{
    int is_long = is_char_in(flaginfo->length_modifier, 'L');
    int is_alt = is_char_in(flaginfo->flags, '#') && flaginfo->precision == 0;
    char *is_nan = get_weird(is_long ? nb_ld : nb_d);
    int nb_len = 0;

    is_nan = !sum ? my_strupper(is_nan) : is_nan;
    nb_len = my_flen(ABS(is_long ? nb_ld : nb_d), flaginfo->precision);
    if (is_alt)
        nb_len++;
    return flag_e_sub_sub(flaginfo, nb_d, nb_ld, 0);
}

int my_print_flag_e(flaginfo_t *flaginfo, va_list list, int *sum)
{
    long double nb_ld = 0;
    double nb_d = 0;
    int is_long = is_char_in(flaginfo->length_modifier, 'L');

    if (is_long) {
        nb_ld = va_arg(list, long double);
    } else {
        nb_d = va_arg(list, double);
    }
    return flag_e_sub(flaginfo, nb_d, nb_ld, sum);
}

int my_print_flag_capse(flaginfo_t *flaginfo, va_list list, int *sum)
{
    my_print_flag_e(flaginfo, list, 0);
}
