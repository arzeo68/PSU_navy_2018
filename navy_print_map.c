/*
** EPITECH PROJECT, 2019
** Repository
** File description:
** print map navy
*/

#include "include/my.h"

int print_map(char **map)
{
    my_putstr("|A B C D E F G H\n-+---------------\n");
    for (int i = 0; map[i]; i++) {
        my_put_nbr(i + 1);
        write(1, "|", 1);
        write(1, map[i], my_strlen(map[i]));
        write(1, "\n", 1);
    }
}

int place_boat(char **arg, navy_t *navy)
{
    int lengh = 0;
    for (int i = 0; arg[i]; i++) {
        lengh = arg[i][0] - 48;
        find_side(arg[i], lengh, navy);
    }
}

int find_side(char *str, int size, navy_t *navy)
{
    if (str[2] != str[5]) {
        place_line(navy, str);
    }
    else if (str[3] != str[6]) {
        place_column(navy, str);
    }
}

char **place_line(navy_t *navy, char *str)
{
    int value = my_getnbr_char(str[0]);
    int line = my_getnbr_char(str[3]);
    int start = my_getnbr_char(str[2]);
    int end = my_getnbr_char(str[5]);
    int size = (end - start);

    start *= 2;
    start -= 2;
    for (int i = 0; i <= size; i++) {
        navy->map->map_player[line - 1][start] = value + '0';
        start += 2;
    }
}

char **place_column(navy_t *navy, char *str)
{
    int value = my_getnbr_char(str[0]);
    int column = my_getnbr_char(str[2]);
    int start = my_getnbr_char(str[3]);
    int end = my_getnbr_char(str[6]);
    int size = (end - start);

    column *= 2;
    column -= 2;
    for (int i = 0; i <= size; i++) {
        navy->map->map_player[start - 1][column] = value + '0';
        start++;
    }
}
