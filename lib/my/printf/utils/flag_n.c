/*
** EPITECH PROJECT, 2024
** FLAG_N
** File description:
** Deal with n conversion_specifier
*/
#include "../my_printf.h"
#include "../../my.h"
#include <stdarg.h>
#include <unistd.h>

int my_print_flag_n(flaginfo_t *flaginfo, va_list list, int *sum)
{
    switch (flaginfo->length_modifier[0]) {
        case 'l':
            if (flaginfo->length_modifier[1] == 'l'){
                *(long long int *)(va_arg(list, void *)) = *sum;
                break;
            }
            *(long int *)(va_arg(list, void *)) = *sum;
            break;
        case 'h':
            if (flaginfo->length_modifier[1] == 'h') {
                *(char *)(va_arg(list, void *)) = *sum;
                break;
            }
            *(short int *)(va_arg(list, void *)) = *sum;
            break;
        default:
            *(int *)(va_arg(list, void *)) = *sum;
            break;
    }
    return 0;
}
