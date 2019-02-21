/*
** EPITECH PROJECT, 2019
** Repository
** File description:
** navy
*/

#include "include/my.h"

#define ABS(X) X = X < 0 ? X * -1 : X

int is_number(char *str)
{
    int status = 0;
    for (int i = my_strlen(str); i >= 0; i--) {
        if (str[i] >= 48 && str[i] <= 57)
            status++;
    }
    status = my_strlen(str) - status;
    return status;
}

char *check_user(char **argv, int argc, navy_t *navy)
{
    if (is_number(argv[1]) != 0)
        return (argv[1]);
    if (argv[2] != NULL)
        if (is_number(argv[2]) != 0)
            return (argv[2]);
    return (NULL);
}

int void_map(navy_t *navy)
{
    int fd = 0;
    char *map = malloc(sizeof(char) * 180);
    char *map_copy = malloc(sizeof(char) * 180);

    if ((fd = open("void_map.txt", O_RDONLY)) < 0)
        return (write(2, "need file\n", 10), 84);
    read(fd, map, 180);
    map_copy = my_strcpy(map_copy, map);
    navy->map->ennemy_map_tab = str_to_tab(map, '\n');
    navy->map->map_player = str_to_tab(map_copy, '\n');
    return (0);
}

int check_boat_lengh(char **str, int k)
{
    int letter = 0;
    int number = 0;
    int size = 0;
    if (str[0] == NULL || str[1] == NULL || str[2] == NULL ||
        is_number(str[0]) != 0)
        return (84);
    size = my_getnbr(str[0]);
    if (str[1][1] != str[2][1]) {
        number = str[2][1] - str[1][1];
        ABS(number);
        if (number == size - 1)
            return (0);
    } else if (str[1][0] != str[2][0]) {
        letter = str[2][0] - str[1][0];
        ABS(letter);
        if (letter == size - 1)
            return (0);
    }
    return (84);
}

int check_argue(navy_t *navy)
{
    int status = 0;
    char **boat_tab = NULL;

    for (int i = 0; i <= 3; i++) {
        boat_tab = str_to_tab(navy->map->arg_tab[i], ':');
        if (check_boat_lengh(boat_tab, i + 2) != 84)
            status++;
        if (check_input(navy->map->arg_tab[i]) == 84)
            return (84);
    }
    status -= 4;
    if (status == 0)
        return (status);
    return (84);
}
