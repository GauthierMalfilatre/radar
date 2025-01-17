/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Check medals
*/
#include "my_radar.h"

int check_big_step(radar_t *radar)
{
    return radar->stat->km_flights >= 1000000000;
}

int check_all_others(radar_t *radar)
{
    for (medals_t *temp = radar->medals; temp; temp = temp->next) {
        if (my_strcmp(temp->name, "One for all") && !temp->is_checked) {
            return 0;
        }
    }
    return 1;
}

int check_litle_land(radar_t *radar)
{
    return radar->stat->planes_landed >= 200;
}

int check_midle_land(radar_t *radar)
{
    return radar->stat->planes_landed >= 1000;
}

int check_big_land(radar_t *radar)
{
    return radar->stat->planes_landed >= 50000;
}
