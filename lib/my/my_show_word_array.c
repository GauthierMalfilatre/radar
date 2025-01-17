/*
** EPITECH PROJECT, 2024
** MY_SHOW_WORD_ARRAY
** File description:
** Show a word array
*/
#include "my.h"
#include <stdlib.h>

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != (void *) 0; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
    return 0;
}
