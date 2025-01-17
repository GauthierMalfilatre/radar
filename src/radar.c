/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** A 2D visualization panel simulating air traffic.
*/
#include "my_radar.h"

void print_framerate(void)
{
    static int first = 1;
    static sfClock * clock;
    static int fps = 0;
    sfTime elapsed;

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        my_printf("%3d FPS \n", fps);
        fps = 0;
        sfClock_restart(clock);
    } else
        fps++;
}

static int print_usage(void)
{
    my_printf("Air traffic simulation panel\nUSAGE\n  ./my_radar [OPTIONS] "
        "path_to_script\n  path_to_script    The path to the script file.\nOPT"
        "IONS\n  -h                print the usage and quit.\nUSER INTERACTION"
        "S\n  'L' key           enable/disable hitboxes and areas.\n  'S' key "
        "          enable/disable sprites.\n\n");
    return 0;
}

static int print_error(void)
{
    my_errstr("./my_radar: bad arguments: retry with -h\n");
    return 84;
}

int main(int argc, char *const *argv)
{
    radar_t *radar;

    if (argc != 2 || 0)
        return print_error();
    if (!my_strcmp(argv[1], "-h"))
        return print_usage();
    radar = create_radar(argv[1]);
    if (!radar)
        return print_error();
    while (sfRenderWindow_isOpen(radar->window)) {
        sfRenderWindow_clear(radar->window, sfBlack);
        radar->scenes[radar->scene_in]->events(radar);
        radar->scenes[radar->scene_in]->timer(radar);
        radar->scenes[radar->scene_in]->mover(radar);
        radar->scenes[radar->scene_in]->render(radar);
        print_framerate();
        sfRenderWindow_display(radar->window);
    }
    destroy_radar(radar);
    return 0;
}
