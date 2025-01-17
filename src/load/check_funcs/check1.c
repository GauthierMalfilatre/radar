/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Check medals
*/
#include "my_radar.h"

int check_big_crash(radar_t *radar)
{
    return radar->stat->planes_crashed >= 50000;
}

int check_midle_crash(radar_t *radar)
{
    return radar->stat->planes_crashed >= 1000;
}

int check_litle_crash(radar_t *radar)
{
    return radar->stat->planes_crashed >= 200;
}

int check_litle_step(radar_t *radar)
{
    return radar->stat->km_flights >= 500000;
}

int check_midle_step(radar_t *radar)
{
    return radar->stat->km_flights >= 10000000;
}
