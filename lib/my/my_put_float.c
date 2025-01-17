/*
** EPITECH PROJECT, 2024
** MY_PUT_NBR
** File description:
** Read the project's name.
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

//TODO: #

int my_put_float(long double f, int precision)
{
    int sum = 0;

    sum += my_putnbr_ll(f);
    sum += my_putchar('.');
    f = f - (int)f;
    sum += my_put_round(f, precision);
    return sum;
}

int my_flen(long double f, int precision)
{
    int sum = my_nbrlen(f, 10);
    long double dec = f - (int) f;

    sum += precision ? 1 : 0;
    sum += precision;
    return sum;
}

double my_fmod(double x, double y)
{
    int sign = 1;

    if (x < 0) {
        return y + x;
    }
    if (y == 0.0) {
        return 0.0 / 0.0;
    }
    if (x < 0) {
        sign = -1;
        x = -x;
    }
    if (y < 0) {
        y = -y;
    }
    while (x >= y) {
        x -= y;
    }
    return sign * x;
}

/* If i only could, i'll get a better round */

int my_put_round(long double f, int precision)
{
    char *kronk_buffer = malloc(precision + 2);

    if (!kronk_buffer)
        return 0;
    f += 0.5 * my_pow(10, -1 * precision);
    for (int i = 0; i < precision; i++) {
        f *= 10;
        kronk_buffer[i] = '0' + (int)f;
        f -= (int)f;
    }
    kronk_buffer[precision] = '\0';
    my_putstr(kronk_buffer);
    free(kronk_buffer);
    return precision;
}

/*
int my_put_round(long double f, int precision)
{
    char *kronk_buffer = malloc(precision + 1);
    int i;

    precision += 1;
    for (int i = 0; i < precision; i++) {
        f *= 10;
        kronk_buffer[i] = '0' + (int)f;
        f = f - (int)f;
    }
    if (kronk_buffer[precision - 1] > '5') {
        for (i = precision - 2; i >= 0 && kronk_buffer[i] == '9'; i--) {
            kronk_buffer[i] = '0';
        }
        kronk_buffer[i] += 1;
    }
    kronk_buffer[precision - 1] = '\0';
    my_putstr(kronk_buffer);
    free(kronk_buffer);
    return precision;
}
*/
