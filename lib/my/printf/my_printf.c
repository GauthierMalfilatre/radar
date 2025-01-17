/*
** EPITECH PROJECT, 2024
** NOP
** File description:
** Sugar david
*/
#include "../my.h"
#include "my_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static void free_flaginfo(flaginfo_t *flaginfo)
{
    free(flaginfo->flags);
    free(flaginfo->length_modifier);
    free(flaginfo);
    return;
}

static void free_flaginfo_list(linked_clist_t *start)
{
    if (((linked_clist_t *)(start->next))->next) {
        free_flaginfo_list(start->next);
    } else {
        free(start->next);
    }
    free_flaginfo(start->data);
    free(start);
    return;
}

int my_printf(char const *format, ...)
{
    va_list argv;
    int sum = 0;
    linked_clist_t *start = frag(format);

    va_start(argv, format);
    for (linked_clist_t *element = start; element->next;
        element = element->next) {
        printf_ag(element->data, argv, &sum);
    }
    free_flaginfo_list(start);
    va_end(argv);
    return sum;
}
