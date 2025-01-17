/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Create textures linked list for my_radar
*/
#include "my_radar.h"

int create_texture(texture_t **textures, char *name, char *path)
{
    texture_t *new = malloc(sizeof(texture_t));

    new->name = my_strdup(name);
    new->next = *textures;
    new->texture = sfTexture_createFromFile(path, 0);
    *textures = new;
    return 0;
}

sfTexture *get_texture(texture_t *textures, char *name)
{
    for (texture_t *temp = textures; temp; temp = temp->next) {
        if (!my_strcmp(temp->name, name)) {
            return temp->texture;
        }
    }
    return 0;
}

int destroy_textures(texture_t *textures)
{
    if (textures->next) {
        destroy_textures(textures->next);
    }
    free(textures->name);
    sfTexture_destroy(textures->texture);
    free(textures);
    return 0;
}
