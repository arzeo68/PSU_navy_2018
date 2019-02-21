/*
** EPITECH PROJECT, 2019
** repository
** File description:
** epitech
*/

#ifndef MY_STRUCT_S
#define MY_STRUCT_S

typedef struct player_s {
    int *pos[20];
} player_t;

typedef struct map_s {
    char *arg_str;
    char **arg_tab;
    char **ennemy_map_tab;
    char **map_player;
} map_t;

typedef struct navy_s {
    int pid;
    map_t *map;
    player_t *player;
    int playing;
} navy_t;

#endif
