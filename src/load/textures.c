/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Load textures linked list for my_radar
*/
#include "my_radar.h"

static void load_textures_bis(texture_t **new)
{
    create_texture(new, "plane_12", PP("lollipop.png"));
    create_texture(new, "plane_13", PP("eliott.png"));
    create_texture(new, "plane_14", PP("ladybug.png"));
    create_texture(new, "plane_15", PP("ovni.png"));
    create_texture(new, "plane_16", PP("buzz.png"));
    create_texture(new, "plane_17", PP("destroyer.png"));
    create_texture(new, "plane_18", PP("blackcat.png"));
}

texture_t *load_textures(void)
{
    texture_t *new = 0;

    create_texture(&new, "pass", PP("pass.png"));
    create_texture(&new, "world", PP("worldmap2.jpg"));
    create_texture(&new, "menu_1", PP("menu.png"));
    create_texture(&new, "plane_1", PP("plane_base.png"));
    create_texture(&new, "plane_2", PP("b2.png"));
    create_texture(&new, "yohann", PP("yohann_.png"));
    create_texture(&new, "tower_1", PP("tower.png"));
    create_texture(&new, "plane_3", PP("plane_3.png"));
    create_texture(&new, "plane_4", PP("zeppelin.png"));
    create_texture(&new, "plane_5", PP("V2.png"));
    create_texture(&new, "plane_6", PP("starship.png"));
    create_texture(&new, "plane_7", PP("biplan.png"));
    create_texture(&new, "plane_8", PP("mirage.png"));
    create_texture(&new, "plane_9", PP("tigre.png"));
    create_texture(&new, "plane_10", PP("monster.png"));
    create_texture(&new, "plane_11", PP("shrek.png"));
    load_textures_bis(&new);
    return new;
}
