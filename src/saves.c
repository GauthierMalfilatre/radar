/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Radar saves manager file
*/
#include "my_radar.h"
#include <sys/stat.h>
#include <fcntl.h>

static void switch_line_sub(int i, char *buffer, medals_t *temp)
{
    if (!my_strncmp(temp->name, buffer, my_strlen(temp->name))) {
        temp->is_checked = sfTrue;
    }
}

static void swith_line(int i, char *buffer, radar_t *radar)
{
    switch (i) {
        case 0:
        radar->stat->km_flights = my_getnbr(buffer);
        break;
        case 1:
        radar->stat->planes_launched = my_getnbr(buffer);
        break;
        case 2:
        radar->stat->planes_crashed = my_getnbr(buffer);
        break;
        default:
        for (medals_t *temp = radar->medals; temp; temp = temp->next) {
            switch_line_sub(i, buffer, temp);
        }
    }
}

int load_save(char *path, radar_t *radar)
{
    FILE *fd = fopen(path, "r+");
    char *buffer = 0;
    size_t len = 0;

    if (!fd)
        return 0 * my_printf("Error while loading file %s\n", path);
    for (int i = 0; getline(&buffer, &len, fd) != -1; i++) {
        swith_line(i, buffer, radar);
    }
    free(buffer);
    unlock_skins_on_loading(radar);
    radar->skin_index = 0;
    return 0;
}

static void my_fwrite_int(int *n, FILE *fp)
{
    char *temp = int_to_str(*n);

    fwrite(temp, sizeof(char), my_strlen(temp), fp);
    fwrite("\n", 1, 1, fp);
    free(temp);
}

int save(char *path, radar_t *radar)
{
    FILE *fp = fopen(path, "w+");
    int a = (int) radar->stat->km_flights;

    if (!fp) {
        return my_printf("Error while loading file %s\n", path);
    }
    my_fwrite_int(&a, fp);
    my_fwrite_int(&radar->stat->planes_launched, fp);
    my_fwrite_int(&radar->stat->planes_crashed, fp);
    my_fwrite_int(&radar->stat->planes_landed, fp);
    for (medals_t *temp = radar->medals; temp; temp = temp->next) {
        if (temp->is_checked) {
            fwrite(temp->name, sizeof(char), my_strlen(temp->name), fp);
            fwrite("\n", 1, 1, fp);
        }
    }
    fclose(fp);
    return 0;
}
