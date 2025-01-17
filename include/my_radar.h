/*
** EPITECH PROJECT, 2024
** MY_RADAR
** File description:
** Header file for my_radar project
*/
#ifndef MY_RADAR_H
    #define MY_RADAR_H
    #define PLANE(value) ((plane_t *)(value->infos))
    #define TOWER(value) ((tower_t *)(value->infos))
    #define TEAPOT(value) ((teapot_t *)(value->infos))
    #define PP(name) ("assets/pictures/" name)
    #define FP(name) ("assets/fonts/" name)
    #define V2F(a, b) ((sfVector2f){a, b})
    #include "my.h"
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <math.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #define CM(...) create_medal(__VA_ARGS__)
    #define NSCENES 4
    #define WIN_W 1920
    #define WIN_H 1080

// Enum for actual scene
enum scenes_e {
    TRAFIK_S,
    MENU_S,
    MEDALS_S,
    PILOT_S,
};

// Enum for type of actors
enum actor_e {
    TEAPOT_A,
    PLANE_A,
    TOWER_A,
};

// Enum for type of shape
enum shape_e {
    RECT_S,
    CIRCLE_S,
};

// Different types of actors
/* Planes */
typedef struct plane_s {
    sfSprite *sprite;
    sfRectangleShape *hitbox;
    sfClock *clock;
    double delta_t;
    sfVector2f pos;
    sfVector2f blue_origin;
    sfVector2f target;
    sfVector2f vel;
    double rotation_angle;
    double speed;
    double delay;
    sfBool is_launched;
    int (*time)();
    int (*move)();
    int (*render)();
    int (*destroyer)();
} plane_t;

/* Towers */
typedef struct tower_s {
    sfSprite *sprite;
    sfCircleShape *hitbox;
    sfVector2f pos;
    double area;
    int (*render)();
    int (*destroyer)();
} tower_t;

/* Teapots */
typedef struct teapot_s {
    sfSprite *sprite;
    sfVector2f pos;
    sfRectangleShape *rshape;
    sfCircleShape *cshape;
    int typofshape;
    int (*render)();
    int (*destroyer)();
} teapot_t;

// Actor linked struct
typedef struct actor_s {
    int type;
    char *name;
    void *infos;
    struct actor_s *next;
    struct actor_s *prev;
} actor_t;

// Scene struct
/*
** We're not gonna use scenes linked list this time, 'cause we have array
** of structures
*/
typedef struct scene_s {
    actor_t *actors;
    sfClock *clock;
    int offset;
    int (*destroyer)();
    int (*events)();
    int (*timer)();
    int (*mover)();
    int (*render)();
} scene_t;

// Textures linked list
typedef struct texture_s {
    char *name;
    sfTexture *texture;
    struct texture_s *next;
} texture_t;

// Achievements linked list
typedef struct medals_s {
    char *name;
    char *description;
    sfBool is_checked;
    int (*checker)();
    struct medals_s *next;
} medals_t;

// Stats struct
typedef struct stat_s {
    int planes_launched;
    int planes_landed;
    int planes_crashed;
    long double km_flights;
    int pilot_pass_level;
} stat_t;

// Skins struct
typedef struct skins_s {
    int type_of;
    char *name;
    sfBool is_unlocked;
    sfTexture *texture;
    struct skins_s *next;
    struct skins_s *prev;
} skins_t;

// Game struct
typedef struct radar_s {
    sfRenderWindow *window;
    sfVideoMode videomode;
    scene_t *scenes[NSCENES];
    texture_t *textures;
    medals_t *medals;
    skins_t *skin;
    sfEvent event;
    sfBool is_hitbox_visibles;
    sfBool is_sprite_visibles;
    stat_t *stat;
    sfMusic *music;
    int scene_in;
    int skin_index;
} radar_t;

// Just utils
sfVector2f fvectmul(sfVector2f vector, double mul1, double mul2);
sfVector2f get_dir(sfVector2f pos1, sfVector2f pos2, double speed);
double get_norme(sfVector2f pos1, sfVector2f pos2);
int is_pressed(sfEvent evt, int key);
void draw_string(sfRenderWindow *window, char *str, sfVector2f pos,
    sfVector2f size);
char *int_to_str(int n);
double get_bnorme(sfVector2f pos1, sfVector2f pos2);
void draw_int(radar_t *radar, int n, sfVector2f pos, sfVector2f scale);

// Random
int change_skinof_plane(actor_t *actors, sfTexture *texture);
void bocollider(scene_t *scene, int *crashed, radar_t *radar);
int unlock_skins_on_loading(radar_t *radar);
int next_skin_plane(radar_t *radar, actor_t *actors, int n);

// Create and destroy
/* Game */
radar_t *create_radar(char *file);
int destroy_radar(radar_t *radar);

/* Textures */
int create_texture(texture_t **textures, char *name, char *path);
int destroy_textures(texture_t *textures);

/* Scenes */
scene_t *create_trafik(radar_t *radar, char *file);
scene_t *create_menu(radar_t *radar);
scene_t *create_medalss(radar_t *radar);
scene_t *create_pilot(radar_t *radar);

/* Actors */
int add_actor(actor_t **actors, int type, void *infos, char *name);
int destroy_actor(actor_t *actor);
int destroy_one_actor(actor_t **head, actor_t *todel);

plane_t *create_plane(sfTexture *texture, sfVector2f pos, sfVector2f target,
    sfVector2f speedanddelay);
int destroy_plane(plane_t *plane);

teapot_t *create_teapot(sfTexture *texture, sfVector2f size, sfVector2f pos);
int destroy_teapot(teapot_t *teapot);

tower_t *create_tower(sfTexture *texture, sfVector2f pos, double area);
int destroy_tower(tower_t *tower);

/* Medals */

void create_medal(medals_t **head, int (*checker)(),
    char *name, char *description);

/* Skins */
void create_skin(skins_t **head, sfTexture *texture, int type, char *name);

// Load
/* Medals */
medals_t *load_medals(void);

/* Skinks */
skins_t *load_skin(texture_t *textures);

/* Textures */
texture_t *load_textures(void);

/* Scenes */
actor_t *load_trafik_actors(texture_t *textures, char *file);
actor_t *load_menu_actors(texture_t *textures);
actor_t *load_medals_actors(texture_t *textures);
actor_t *load_pilot_actors(texture_t *textures);

// Get
/* Textures */
sfTexture *get_texture(texture_t *textures, char *name);

/* Actor */
actor_t *get_actor(actor_t *actors, char *name);

// Scenes related functions
/* Trafik */
int trafik_time(radar_t *radar);
int trafik_move(radar_t *radar);
int trafik_render(radar_t *radar);
int trafik_events(radar_t *radar);
int trafik_destroyer(scene_t *scene);

/* Menu */
int menu_time(radar_t *radar);
int menu_move(radar_t *radar);
int menu_render(radar_t *radar);
int menu_events(radar_t *radar);
int menu_destroyer(scene_t *scene);

/* Medals */
int medals_time(radar_t *radar);
int medals_move(radar_t *radar);
int medals_render(radar_t *radar);
int medals_events(radar_t *radar);
int medals_destroyer(scene_t *scene);

/* Pilot pass */
int pilot_time(radar_t *radar);
int pilot_move(radar_t *radar);
int pilot_render(radar_t *radar);
int pilot_events(radar_t *radar);
int pilot_destroyer(scene_t *scene);

// Saving
int load_save(char *path, radar_t *radar);
int save(char *path, radar_t *radar);

// Medals chekers
int check_litle_step(radar_t *radar);
int check_midle_step(radar_t *radar);
int check_big_step(radar_t *radar);

int check_litle_crash(radar_t *radar);
int check_midle_crash(radar_t *radar);
int check_big_crash(radar_t *radar);

int check_litle_land(radar_t *radar);
int check_midle_land(radar_t *radar);
int check_big_land(radar_t *radar);

int check_all_others(radar_t *radar);
#endif
