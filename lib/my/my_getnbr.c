/*
** EPITECH PROJECT, 2024
** MY_GETNBR
** File description:
** Get an int from a string
*/
#include "my.h"

static int check_overflow(char i, int nbr, int neg)
{
    if (neg && nbr >= 214748364 && i - 48 > 2147483647 - (nbr) * 10) {
        return 1;
    } else if (!neg && nbr <= -214748364 && i - 48 < -2147483648 + nbr * 10) {
        return 1;
    }
    return 0;
}

static int check_digit(char i)
{
    return (i >= '0' && i <= '9');
}

static int check_neg(char i, int nbr, int neg)
{
    if (i == '-' && !nbr) {
        return -1;
    }
    return 1;
}

static int check(char i, int nbr, int neg)
{
    int temp_nbr = nbr;

    if (check_digit(i)) {
        if (neg == -1 && nbr > 0) {
            temp_nbr *= -1;
        }
        return temp_nbr * 10 + neg * (i - 48);
    }
    return temp_nbr;
}

int my_getnbr(char const *str)
{
    int nbr = 0;
    int neg = 1;

    for (int i = 0; str[i]; i++) {
        if (check_overflow(str[i], nbr, neg)) {
            return 0;
        }
        if (check_digit(str[i]) || str[i] == '-' || str[i] == '+') {
            neg *= check_neg(str[i], nbr, neg);
            nbr = check(str[i], nbr, neg);
        } else {
            return nbr;
        }
    }
    return nbr;
}

double my_getfloat(char const *str)
{
    double res = my_getnbr(str);
    int j = my_nbrlen((int) res, 10);

    if (!str[j] || str[j] != '.') {
        return res;
    }
    j++;
    for (int i = 0; str[i + j]; i++) {
        if (check_digit(str[i + j])) {
            res += (str[i + j] - '0') / my_pow(10, 1 + i);
        } else {
            return res;
        }
    }
    return res;
}
