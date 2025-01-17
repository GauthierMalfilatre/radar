/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Skins related functions
*/
#include "my_radar.h"

int change_skinof_plane(actor_t *actors, sfTexture *texture)
{
    for (actor_t *temp = actors; temp; temp = temp->next) {
        if (temp->type == PLANE_A) {
            sfSprite_setTexture(((plane_t *) temp->infos)->sprite, texture, 0);
        }
    }
    return 0;
}

static int count_nb_skins(skins_t *skin)
{
    int len = 0;

    for (skins_t *temp = skin; temp; temp = temp->next) {
        len++;
    }
    return len;
}

int next_skin_plane(radar_t *radar, actor_t *actors, int n)
{
    int i = 0;

    unlock_skins_on_loading(radar);
    radar->skin_index += n;
    if (radar->skin_index < 0)
        radar->skin_index = count_nb_skins(radar->skin) - 1;
    if (radar->skin_index > count_nb_skins(radar->skin) - 1) {
        radar->skin_index = 0;
    }
    for (skins_t *temp = radar->skin; temp; temp = temp->next) {
        if (!temp->is_unlocked) {
            i++;
            continue;
        }
        if (radar->skin_index == i) {
            change_skinof_plane(actors, temp->texture);
            return 0;
        }
        i++;
    }
}

int unlock_skins_on_loading(radar_t *radar)
{
    int count = 300;

    for (skins_t *skin = radar->skin; skin; skin = skin->next) {
        if (radar->stat->km_flights * 300 / 10000000 >= count) {
            skin->is_unlocked = sfTrue;
        }
        count += 300;
    }
}

static void load_skin2(texture_t *textures, skins_t **new)
{
    create_skin(new, get_texture(textures, "plane_3"), PLANE_A, "valheim");
    create_skin(new, get_texture(textures, "plane_15"), PLANE_A, "ovni");
    create_skin(new, get_texture(textures, "plane_2"), PLANE_A, "B2");
}

skins_t *load_skin(texture_t *textures)
{
    skins_t *new = (void *) 0;

    create_skin(&new, get_texture(textures, "plane_1"), PLANE_A, "BASE");
    create_skin(&new, get_texture(textures, "yohann"), PLANE_A, "bigboss");
    create_skin(&new, get_texture(textures, "plane_13"), PLANE_A, "eliott");
    create_skin(&new, get_texture(textures, "plane_9"), PLANE_A, "tigre");
    create_skin(&new, get_texture(textures, "plane_8"), PLANE_A, "mirage");
    create_skin(&new, get_texture(textures, "plane_11"), PLANE_A, "monster");
    create_skin(&new, get_texture(textures, "plane_18"), PLANE_A, "chatnoir");
    create_skin(&new, get_texture(textures, "plane_12"), PLANE_A, "shrek");
    create_skin(&new, get_texture(textures, "plane_14"), PLANE_A, "ladybug");
    create_skin(&new, get_texture(textures, "plane_10"), PLANE_A, "lollipop");
    create_skin(&new, get_texture(textures, "plane_6"), PLANE_A, "starship");
    create_skin(&new, get_texture(textures, "plane_7"), PLANE_A, "biplan");
    create_skin(&new, get_texture(textures, "plane_5"), PLANE_A, "V2");
    create_skin(&new, get_texture(textures, "plane_16"), PLANE_A, "buzz");
    create_skin(&new, get_texture(textures, "plane_17"), PLANE_A, "destroyer");
    create_skin(&new, get_texture(textures, "plane_4"), PLANE_A, "zeppelin");
    load_skin2(textures, &new);
    return new;
}
