/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Create medals linked list.
*/
#include "my_radar.h"

void create_medal(medals_t **head, int (*checker)(),
    char *name, char *description)
{
    medals_t *new = malloc(sizeof(medals_t));

    new->name = name;
    new->description = description;
    new->checker = checker;
    new->is_checked = sfFalse;
    new->next = *head;
    *head = new;
}
