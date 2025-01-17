/*
** EPITECH PROJECT, 2024
** MY_PUTNBR_BASE
** File description:
** Put nbr in a base
*/
#include "my.h"
#include <unistd.h>

static int my_putnbr_base_pre(unsigned long int nbr, char const *base)
{
    int nbase = my_strlen(base);
    char res[8 * 5];
    long n = nbr;
    int i = 0;

    if (n < 0) {
        n *= -1;
        my_putstr("-");
    }
    for (; i < 8 * 4 && n > 0; i++) {
        if (n < nbase) {
            res[i] = base[n];
            break;
        }
        res[i] = base[n % nbase];
        n = (n - n % nbase) / nbase;
    }
    res[i + 1] = '\0';
    my_revstr(res);
    return my_putstr(res);
}

static int my_putnbr_base_pre_ull(unsigned long long int nbr, char const *base)
{
    int nbase = my_strlen(base);
    char res[8 * 5];
    unsigned long long int n = nbr;
    int i = 0;

    for (; i < 8 * 4 && n > 0; i++) {
        if (n < nbase) {
            res[i] = base[n];
            break;
        }
        res[i] = base[n % nbase];
        n = (n - n % nbase) / nbase;
    }
    res[i + 1] = '\0';
    my_revstr(res);
    return my_putstr(res);
}

int my_putnbr_base(unsigned long int nbr, char const *base)
{
    if (nbr) {
        return my_putnbr_base_pre(nbr, base);
    }
    return my_putstr("0");
}

int my_putnbr_base_ull(unsigned long long int nbr, char const *base)
{
    if (nbr) {
        return my_putnbr_base_pre_ull(nbr, base);
    }
    return my_putstr("0");
}
