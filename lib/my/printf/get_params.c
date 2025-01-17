/*
** EPITECH PROJECT, 2024
** MY_PRINTF
** File description:
** Get params
** %[$][flags][width][.precision][length modifier]conversion
** [ctrl][alt][succeed]
*/
#include "../my.h"
#include "my_printf.h"
#include <stdlib.h>

static int is_flag(char c)
{
    char flags[5] = "#0- +";

    for (int i = 0; i < 5; i++) {
        if (c == flags[i])
            return 1;
    }
    return 0;
}

static int is_length(char c)
{
    char flags[6] = "hlLjzt";

    for (int i = 0; i < 6; i++) {
        if (c == flags[i])
            return 1;
    }
    return 0;
}

static int is_specifier(char c)
{
    char flags[20] = "diouxXeEfFaAgGcspnm%";

    for (int i = 0; i < 20; i++) {
        if (c == flags[i])
            return 1;
    }
    return 0;
}

static int get_flags(flaginfo_t *dest, char const *str)
{
    int i = 0;

    for (; is_flag(str[i]); i++) {
        my_strncat(dest->flags, &str[i], 1);
    }
    return i;
}

static int get_specifiers(flaginfo_t *dest, char const *str)
{
    dest->conversion = str[0];
    return 1;
}

int get_width(flaginfo_t *dest, char const *str)
{
    dest->width = my_getnbr(str);
    dest->width -= !dest->width;
    if (dest->width == -1) {
        return 0;
    }
    return my_nbrlen(dest->width, 10);
}

int get_precision(flaginfo_t *dest, char const *str)
{
    if (str[0] != '.') {
        dest->precision = -1;
        return 0;
    }
    dest->precision = my_getnbr(&str[1]);
    return my_nbrlen(dest->precision, 10) + 1;
}

int get_length(flaginfo_t *dest, char const *str)
{
    int i = 0;

    for (; is_length(str[i]); i++) {
        my_strncat(dest->length_modifier, &str[i], 1);
    }
    return i;
}

flaginfo_t *new_flaginfo(void)
{
    flaginfo_t *new = malloc(sizeof(flaginfo_t));

    new->flags = malloc(sizeof(char) * (5 + 1));
    for (int i = 0; i < 6; i++) {
        new->flags[i] = '\0';
    }
    new->length_modifier = malloc(sizeof(char) * (2 + 1));
    for (int i = 0; i < 2; i++) {
        new->length_modifier[i] = '\0';
    }
    new->width = 0;
    new->precision = 0;
    new->conversion = '\0';
    return new;
}

flaginfo_t *str_to_flaginfo(char const *format)
{
    flaginfo_t *new = new_flaginfo();
    int offset = 1;
    char targeted[5] = "feEgG";

    offset += get_flags(new, &format[offset]);
    offset += get_width(new, &format[offset]);
    offset += get_precision(new, &format[offset]);
    offset += get_length(new, &format[offset]);
    offset += get_specifiers(new, &format[offset]);
    if (new->precision != -1) {
        return new;
    }
    for (int i = 0; i < 5; i++) {
        if (new->conversion == targeted[i]) {
            new->precision = 6;
            break;
        }
    }
    return new;
}
