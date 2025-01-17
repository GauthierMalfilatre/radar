/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Load actors linked list for scenes of my_radar
*/
#include "my_radar.h"

static void add_plane(actor_t **actors, char **array, sfTexture *texture)
{
    add_actor(actors, PLANE_A, create_plane(texture,
        (sfVector2f) {my_getnbr(array[1]), my_getnbr(array[2])},
            (sfVector2f) {my_getnbr(array[3]), my_getnbr(array[4])},
                (sfVector2f) {my_getnbr(array[5]), my_getfloat(array[6])}),
                    "plane");
}

static void add_tower(actor_t **actors, char **array, sfTexture *texture)
{
    add_actor(actors, TOWER_A, create_tower(texture,
        (sfVector2f) {my_getnbr(array[1]), my_getnbr(array[2])},
            my_getnbr(array[3])), "tower");
}

static int my_check_array(char **array, int lent)
{
    int len = 0;

    for (; array[len]; len++);
    if (len != lent) {
        return 1;
    }
    for (int i = 1; array[i]; i++) {
        if (!my_str_isnum(array[i])) {
            return 1;
        }
    }
    return 0;
}

static int read_config_files_sub(char *buffer, actor_t **actors,
    sfTexture *plane_texture, sfTexture *tower_texture)
{
    char **array;

    if (!my_strcmp(buffer, "\n"))
        return 0;
    array = my_str_to_word_array(buffer);
    if (!array || !array[0])
        return -1;
    if (!my_strcmp(array[0], "A")) {
        if (my_check_array(array, 7))
            return -1 + 0 * my_free_word_array(array);
        add_plane(actors, array, plane_texture);
    }
    if (!my_strcmp(array[0], "T")) {
        if (my_check_array(array, 4))
            return -1 + 0 * my_free_word_array(array);
        add_tower(actors, array, tower_texture);
    }
    if (my_strcmp(array[0], "A") && my_strcmp(array[0], "T"))
        return -1 + 0 * my_free_word_array(array);
    return 0 * my_free_word_array(array);
}

static int read_config_file(char *path, actor_t **actors,
    sfTexture *plane_texture, sfTexture *tower_texture)
{
    FILE *src = fopen(path, "r");
    char *buffer = NULL;
    size_t len;

    if (!src)
        return -1;
    while (getline(&buffer, &len, src) != -1) {
        if (read_config_files_sub(buffer, actors, plane_texture,
            tower_texture) == -1) {
            free(buffer);
            return -1;
        }
    }
    fclose(src);
    free(buffer);
    return 0;
}

actor_t *load_trafik_actors(texture_t *textures, char *file)
{
    actor_t *actors = 0;

    add_actor(&actors, TEAPOT_A, create_teapot(get_texture(textures, "world"),
        (sfVector2f) {1, 1}, (sfVector2f) {0, 0}), "world");
    if (read_config_file(file, &actors, get_texture(textures, "plane_1"),
        get_texture(textures, "tower_1")) == -1) {
            destroy_actor(actors);
            return 0;
        }
    return actors;
}

actor_t *load_menu_actors(texture_t *textures)
{
    actor_t *actors = 0;

    add_actor(&actors, TEAPOT_A, create_teapot(get_texture(textures, "menu_1"),
        (sfVector2f) {1, 1}, (sfVector2f) {0, 0}), "menu_1");
    return actors;
}

actor_t *load_medals_actors(texture_t *textures)
{
    actor_t *actors = 0;

    return actors;
}

actor_t *load_pilot_actors(texture_t *textures)
{
    actor_t *actors = 0;

    add_actor(&actors, TEAPOT_A, create_teapot(get_texture(textures,
        "plane_1"), (sfVector2f) {-10, -10}, (sfVector2f) {0, 0}), "skin");
    return actors;
}
