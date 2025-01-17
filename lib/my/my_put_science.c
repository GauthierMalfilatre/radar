/*
** EPITECH PROJECT, 2024
** PUT_SCIENCE
** File description:
** Science waits for his next revolution : ouais !
*/

#include "my.h"
#include "printf/my_printf.h"

//#include <stdio.h>
//TODO: nan inf etc...
//TODO: sub 1 abs f's
//TODO: sub 1 ABS rounding
//TODO: 0

static int my_put_exponent(int exponent, int is_caps)
{
    int sum = 0;

    sum += my_putchar(is_caps ? 'E' : 'e');
    sum += my_putchar(exponent >= 0 ? '+' : '-');
    if (ABS(exponent) < 10) {
        sum += my_putchar('0');
    }
    sum += my_putnbr(ABS(exponent));
    return sum;
}

static int my_put_pi(long long int aqua, int precision, int *exponent)
{
    int sum = 0;
    int size = 0;
    int power;

    if (aqua == 0) {
        sum += my_putchar('0');
        if (precision > 0)
            sum += my_putchar('.');
    }
    for (; my_pow(10, size) <= aqua; size++);
    for (int i = 1; i <= size && i <= precision + 1; i++) {
        power = my_pow(10, size - i);
        sum += my_putchar('0' + (aqua / power) % 10);
        (*exponent)++;
        if (i == 1 && precision)
            sum += my_putchar('.');
        if (i > precision)
            break;
    }
    return sum;
}

int my_put_science(long double f, int precision, int is_caps)
{
    int sum = 0;
    int start = my_nbrlen(f, 10) - 1;
    long long int power;
    int exponent = -1;
    long double dec;

    for (; (int)f == 0; f *= 10) {
        exponent--;
    }
    if (f < 0) {
        sum += my_putchar('-');
        f *= -1;
    }
    my_put_pi(ABS(f), precision, &exponent);
    precision -= my_nbrlen(f, 10) - 1;
    f = f - (int)f;
    sum += my_put_round(f, precision);
    sum += my_put_exponent(exponent, is_caps);
    return sum;
}
