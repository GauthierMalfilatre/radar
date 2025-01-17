/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Load medals linked list.
*/
#include "my_radar.h"

medals_t *load_medals(void)
{
    medals_t *new = (void *) 0;

    CM(&new, &check_big_step, "Heavy driver", "Fly over 1000000000km");
    CM(&new, &check_midle_step, "Wilco", "Fly over 10000000km");
    CM(&new, &check_litle_step, "A litlle step", "Fly over 500000km");
    CM(&new, &check_litle_crash, "Ka-boom!", "Crash over 200 plane");
    CM(&new, &check_midle_crash, "Oussama", "Crash over 1000 plane");
    CM(&new, &check_big_crash, "Ace", "Crash over 50000 plane");
    CM(&new, 0, "Petit Geek :)", "Have the medal \"Petit Geek :)\"");
    CM(&new, &check_all_others, "One for all", "Have any other medals");
    CM(&new, &check_litle_land, "Sky-lander", "Land over 200 plane");
    CM(&new, &check_midle_land, "Sky-lander 2", "Land over 1000 plane");
    CM(&new, &check_big_land, "Sky-lander 3", "Land over 50000 plane");
    CM(&new, 0, "Deja vu", "Krash a plane over NYC");
    return new;
}
