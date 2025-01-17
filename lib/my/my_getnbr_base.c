/*
** EPITECH PROJECT, 2024
** MY_GETNBR_BASE
** File description:
** Get numbers
*/
#include "my.h"


static int count_occ(char const *str, char c)
{
    int occ = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            occ++;
        }
    }
    return occ;
}

static int get_index(char const *str, char c)
{
    int occ = count_occ(str, '-');

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}

static int get_l_index(char const *str, char c)
{
    int occ = -1;
    int i = 0;

    for (; str[i] != '\0' &&
        occ != count_occ(str, '-') + count_occ(str, '+') - 1; i++) {
        if (str[i] == c || str[i] == '+') {
            occ++;
        }
    }
    return (occ != -1) ? i + 1 : -1;
}

float my_pow(int nb, int p)
{
    int memp = p;
    float base = 1;

    if (p < 0) {
        p *= -1;
    }
    for (; p > 0; p--) {
        base *= (float) nb;
    }
    return memp > 0 ? base : (float) (1.0 / base);
}

int my_getnbr_base(char const *str, char const *base)
{
    long res = 0;
    int nbase = my_strlen(base);
    int neg = count_occ(str, '-');
    int start = get_l_index(str, '-') == -1 ? 0 : get_l_index(str, '-') - 1;

    for (int i = start; str[i] != '\0'; i++) {
        res += get_index(base, str[i]) * my_pow(nbase, my_strlen(str) - i - 1);
        if (get_index(base, str[i]) == -1) {
            return 0;
        }
    }
    return (neg % 2) ? -1 * res : 1 * res;
}
