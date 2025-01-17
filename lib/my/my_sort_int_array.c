/*
** EPITECH PROJECT, 2024
** MY_SORT_INT_ARRAY
** File description:
** Sort an array of integers
*/
#include "my.h"
#include "my.h"

void my_sort_int_array(int *array, int size)
{
    int i = 0;

    while (i < size - 1) {
        if (array[i] > array[i + 1]) {
            my_swap(&array[i], &array[i + 1]);
            i = 0;
        } else {
            i++;
        }
    }
    return;
}
