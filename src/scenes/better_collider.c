/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Trafik scene related functions
*/
#include "my_radar.h"

static int collideplane(plane_t *a1, plane_t *a2, actor_t **actors, int len)
{
    if (a1 == a2) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (actors[i]->type == TOWER_A && (get_norme(a1->pos,
            TOWER(actors[i])->pos) <= TOWER(actors[i])->area + 20 ||
                get_norme(a2->pos, TOWER(actors[i])->pos)
                    <= TOWER(actors[i])->area)) {
            return 0;
        }
    }
    return (a1->pos.x < a2->pos.x + 20
        && a1->pos.x + 20 > a2->pos.x
            && a1->pos.y < a2->pos.y + 20
                && a1->pos.y + 20 > a2->pos.y);
}

static void fill_scorners(actor_t *actors, int *scorners)
{
    int pos;
    sfVector2f poss;

    for (actor_t *temp = actors; temp; temp = temp->next) {
        if (temp->type == PLANE_A) {
            poss = PLANE(temp)->pos;
        }
        if (temp->type == TOWER_A) {
            poss = TOWER(temp)->pos;
        }
        pos = (poss.x > 960.f) + (poss.y > 540.f) * 2;
        scorners[pos]++;
    }
    return;
}

static void fill_corners_sub(actor_t *temp, int *scroners, actor_t ***corners)
{
    int pos;

    if (temp->type == PLANE_A) {
        if (PLANE(temp)->delay > 0)
            return;
        pos = (PLANE(temp)->pos.x > 960) + (PLANE(temp)->pos.y > 540) * 2;
    } else if (temp->type == TOWER_A) {
        pos = (TOWER(temp)->pos.x > 960) + (TOWER(temp)->pos.y > 540) * 2;
    } else {
        return;
    }
    corners[pos][scroners[pos]] = temp;
    scroners[pos]++;
}

static void fill_corners(actor_t ***corners, int *scroners, actor_t *actors)
{
    fill_scorners(actors, scroners);
    for (int i = 0; i < 4; i++) {
        corners[i] = malloc(sizeof(actor_t *) * scroners[i]);
    }
    for (int i = 0; i < 4; i++)
        scroners[i] = 0;
    for (actor_t *temp = actors; temp; temp = temp->next) {
        fill_corners_sub(temp, scroners, corners);
    }
    return;
}

static void check_collision_sub(actor_t ***corners, int *scorners,
    actor_t **actors, int ipii)
{
    int i = ipii % 10;
    int ii = ipii / 10;

    for (int iii = 0; iii < scorners[i]; iii++) {
        if (corners[i][iii]->type != PLANE_A) {
            continue;
        }
        if (collideplane(PLANE(corners[i][ii]),
            PLANE(corners[i][iii]), corners[i], scorners[i])) {
            free(corners[i][ii]->name);
            free(corners[i][iii]->name);
            corners[i][ii]->name = my_strdup("delete");
            corners[i][iii]->name = my_strdup("delete");
        }
    }
}

void check_collision(actor_t ***corners, int *scorners, actor_t **actors,
    int i)
{
    for (int ii = 0; ii < scorners[i]; ii++) {
        if (corners[i][ii]->type != PLANE_A) {
            continue;
        }
        check_collision_sub(corners, scorners, actors, ii * 10 + i);
    }
}

void checkcheck(medals_t *medal)
{
    if (!my_strcmp(medal->name, "Deja vu")) {
        medal->is_checked = sfTrue;
    }
}

void check_korea(actor_t *temp, medals_t *medals)
{
    if (get_norme(PLANE(temp)->pos, (sfVector2f){585, 474}) < 40) {
        for (medals_t *medal = medals; medal; medal = medal->next) {
            checkcheck(medal);
        }
    }
}

void bocollider(scene_t *scene, int *crashed, radar_t *radar)
{
    actor_t **corners[4];
    int scorners[4] = {};
    actor_t *temp2;

    fill_corners(corners, scorners, scene->actors);
    for (int i = 0; i < 4; i++)
        check_collision(corners, scorners, &scene->actors, i);
    for (actor_t *temp = scene->actors; temp;) {
        if (!my_strcmp(temp->name, "delete")) {
            temp2 = temp;
            temp = temp->next;
            check_korea(temp2, radar->medals);
            destroy_one_actor(&scene->actors, temp2);
            (*crashed)++;
        } else
            temp = temp->next;
    }
    for (int i = 0; i < 4; i++)
        free(corners[i]);
    return;
}
