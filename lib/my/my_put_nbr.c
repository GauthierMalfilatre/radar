/*
** EPITECH PROJECT, 2024
** MY_PUT_NBR
** File description:
** Read the project's name.
*/
#include "my.h"
#include <unistd.h>

static int my_putnbr_check(int *nb, int *sum)
{
    if (*nb == -2147483648) {
        write(1, "-2147483648", 11);
        return -1;
    }
    if (*nb < 0) {
        *nb *= -1;
        (*sum)++;
        write(1, "-", 1);
    }
    return 0;
}

static int my_putnbr_check_ll(long long int *nb, int *sum)
{
    if (*nb == -9223372036854775808ULL) {
        my_putstr("-9223372036854775808");
        return -1;
    }
    if (*nb < 0) {
        *nb *= -1;
        (*sum)++;
        write(1, "-", 1);
    }
    return 0;
}

int my_putnbr(int nb)
{
    int sum = 0;

    if (my_putnbr_check(&nb, &sum) == -1) {
        return 11;
    }
    if (nb / 10 > 0) {
        sum += my_putnbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return sum + 1;
}

int my_putnbr_ll(long long int nb)
{
    int sum = 0;

    if (my_putnbr_check_ll(&nb, &sum) == -1) {
        return my_strlen("-9223372036854775808");
    }
    if (nb / 10 > 0) {
        sum += my_putnbr_ll(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return sum + 1;
}

int my_putnbr_ull(unsigned long long int nb)
{
    int sum = 0;

    if (nb / 10 > 0) {
        sum += my_putnbr_ull(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return sum + 1;
}

int my_nbrlen(long long int nb, int base)
{
    int length = 0;

    if (nb <= 0) {
        length++;
        nb *= -1;
    }
    for (; nb > 0; length++) {
        nb /= base;
    }
    return length;
}

int my_nbrlen_ull(unsigned long long int nb, int base)
{
    int length = 0;

    for (; nb > 0; length++) {
        nb /= base;
    }
    return length;
}
