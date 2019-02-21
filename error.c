/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** error.c
*/

#include "include/my.h"

int error_map(navy_t *navy)
{
    if (check_argue(navy) == 84)
        return (84);
    void_map(navy);
    return (0);
}

int check_input(char *str)
{
        if (my_getnbr_char(str[0]) < 2 || my_getnbr_char(str[0]) > 5)
            return (84);
        if (my_getnbr_char(str[3]) < 1 || my_getnbr_char(str[3]) > 8 ||
        my_getnbr_char(str[6]) < 1 || my_getnbr_char(str[6]) > 8)
            return (84);
        if (str[2] < 65 || str[2] > 72 || str[5] < 65 ||
            str[5] > 72)
            return (84);
    return (0);
}

int print_game(navy_t *navy)
{
    my_putstr("my positions:\n");
    print_map(navy->map->map_player);
    write(1, "\n", 1);
    my_putstr("enemy's positions:\n");
    print_map(navy->map->ennemy_map_tab);
}

int check_ennemy_attack(int pos)
{
    if (pos / 10 < 1 || pos / 10 > 8)
        return (84);
    if (pos % 10 < 0 || pos % 10 > 7)
        return (84);
    return (0);
}

int place_point(char c,int pos, char **map)
{
    int column = pos / 10;
    int line = pos % 10;
    printf(" colonne = %d\n", column);

    column *= 2;
    column -= 2;
    map[line ][column] = c;
    return (0);
}
