/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** navy
*/

#include "include/my.h"

int end_game(navy_t *navy)
{
    int boat = 0;
    int j = 0;
    for (int i = 0; navy->map->map_player[i]; i++) {
        for (int j = 0; navy->map->map_player[i][j] != '\n' &&
        navy->map->map_player[i][j] != '\0'; j++) {
            navy->map->map_player[i][j] == '2' ||
            navy->map->map_player[i][j] == '3' ||
            navy->map->map_player[i][j] == '4' ||
            navy->map->map_player[i][j] == '5' ? boat++ : 0;
        }
    }
    if (boat > 0)
        return (1);
    return (0);
}

char check_hit(int pos, navy_t *navy)
{
    int i = pos % 10;
    int j = pos / 10;

    j *= 2;
    j -= 2;
    return(navy->map->map_player[i][j] == '2' ||
    navy->map->map_player[i][j] == '3' ||
    navy->map->map_player[i][j] == '4' ||
    navy->map->map_player[i][j] == '5'? 'x' : 'o');
}
