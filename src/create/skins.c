/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Create skins linked list.
*/
#include "my_radar.h"

void create_skin(skins_t **head, sfTexture *texture, int type, char *name)
{
    skins_t *new = malloc(sizeof(skins_t));

    new->is_unlocked = sfFalse;
    new->type_of = type;
    new->name = name;
    new->texture = texture;
    new->next = *head;
    new->prev = 0;
    if (new->next) {
        new->next->prev = new;
    }
    *head = new;
}
