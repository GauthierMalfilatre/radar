/*
** EPITECH PROJECT, 2024
** MY_SWAP
** File description:
** Swaps two integers
*/
#include "my.h"

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
