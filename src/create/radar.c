/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** A 2D visualization panel simulating air traffic.
*/
#include "my_radar.h"

static int fill_scenes(radar_t *radar, char *file)
{
    radar->scenes[TRAFIK_S] = create_trafik(radar, file);
    if (!radar->scenes[TRAFIK_S]) {
        return -1;
    }
    radar->scenes[MENU_S] = create_menu(radar);
    radar->scenes[MEDALS_S] = create_medalss(radar);
    radar->scenes[PILOT_S] = create_pilot(radar);
    return 0;
}

static stat_t *create_stats(void)
{
    stat_t *stats = malloc(sizeof(stat_t));

    stats->km_flights = 0;
    stats->pilot_pass_level = 0;
    stats->planes_crashed = 0;
    stats->planes_launched = 0;
    stats->planes_landed = 0;
    return stats;
}

static sfMusic *load_music(void)
{
    sfMusic *music = sfMusic_createFromFile("assets/musics/radar.ogg");

    sfMusic_setVolume(music, 5.f);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return music;
}

radar_t *create_radar(char *file)
{
    radar_t *radar = malloc(sizeof(radar_t));

    radar->videomode = (sfVideoMode) {WIN_W, WIN_H, 32};
    radar->textures = load_textures();
    radar->scene_in = TRAFIK_S;
    radar->is_hitbox_visibles = sfTrue;
    radar->is_sprite_visibles = sfTrue;
    radar->music = load_music();
    radar->medals = load_medals();
    radar->skin = load_skin(radar->textures);
    radar->stat = create_stats();
    if (fill_scenes(radar, file) == -1) {
        destroy_textures(radar->textures);
        free(radar);
        return 0;
    }
    radar->window = sfRenderWindow_create(radar->videomode, "MY_RADAR",
        sfClose, 0);
    load_save("saves/mod49209.sav", radar);
    return radar;
}

static void destroy_medals(medals_t *medals)
{
    if (medals->next) {
        destroy_medals(medals->next);
    }
    free(medals);
}

static void destroy_skins(skins_t *skins)
{
    if (skins->next) {
        destroy_skins(skins->next);
    }
    free(skins);
}

int destroy_radar(radar_t *radar)
{
    save("saves/mod49209.sav", radar);
    for (int i = 0; i < NSCENES; i++) {
        radar->scenes[i]->destroyer(radar->scenes[i]);
    }
    sfMusic_stop(radar->music);
    sfMusic_destroy(radar->music);
    destroy_medals(radar->medals);
    destroy_skins(radar->skin);
    sfRenderWindow_destroy(radar->window);
    destroy_textures(radar->textures);
    free(radar->stat);
    free(radar);
    return 0;
}
