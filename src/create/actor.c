/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Create actor for my_radar
*/
#include "my_radar.h"

int add_actor(actor_t **actors, int type, void *infos, char *name)
{
    actor_t *new = malloc(sizeof(actor_t));

    new->infos = infos;
    new->name = my_strdup(name);
    new->type = type;
    new->next = *actors;
    new->prev = 0;
    if (new->next) {
        new->next->prev = new;
    }
    *actors = new;
    return 0;
}

actor_t *get_actor(actor_t *actors, char *name)
{
    for (actor_t *temp = actors; temp; temp = temp->next) {
        if (!my_strcmp(name, temp->name)) {
            return temp;
        }
    }
    return 0;
}

int destroy_one_actor(actor_t **head, actor_t *todel)
{
    if (!todel->prev)
        *head = todel->next;
    else
        todel->prev->next = todel->next;
    if (todel->next)
        todel->next->prev = todel->prev;
    switch (todel->type) {
        case PLANE_A:
            PLANE(todel)->destroyer(PLANE(todel));
            break;
        case TOWER_A:
            TOWER(todel)->destroyer(TOWER(todel));
            break;
        default:
            TEAPOT(todel)->destroyer(TEAPOT(todel));
            break;
    }
    free(todel->name);
    free(todel);
    return 0;
}

int destroy_actor(actor_t *actor)
{
    if (actor->next) {
        destroy_actor(actor->next);
    }
    switch (actor->type) {
        case PLANE_A:
            PLANE(actor)->destroyer(PLANE(actor));
            break;
        case TOWER_A:
            TOWER(actor)->destroyer(TOWER(actor));
            break;
        default:
            TEAPOT(actor)->destroyer(TEAPOT(actor));
            break;
    }
    free(actor->name);
    free(actor);
    return 0;
}

// Todo:
// Achievements
// Gacha
// Battlepass
// Statistiques
