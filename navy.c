/*
** EPITECH PROJECT, 2019
** Repository
** File description:
** navy
*/
#include <signal.h>
#include "include/my.h"
#include "include/convert.h"
#include "include/get_next_line.h"
#include "include/sig.h"

void print_help(void)
{
    my_putstr("USAGE\n     ./navy [first_player_pid]\nDESCRIPTION\n     ");
    my_putstr("first_player_pid: only for the 2nd player. pid of the first ");
    my_putstr("player.\n     navy positions: file representing the ");
    my_putstr("positions of the ships.");
}

int navy_open_read_file(char **filepath, navy_t *navy, int argc)
{
    int fd = 0;
    char *str = check_user(filepath, argc, navy);
    char *map = malloc(sizeof(char) * 32);

    if (str == NULL)
        return (84);
    navy->map->arg_str = malloc(sizeof(my_strlen(str)));
    if ((fd = open(str, O_RDONLY)) < 0)
        return (write(2, "need file\n", 10), 84);
    read(fd, map, 32);
    navy->map->arg_str = map;
    navy->map->arg_tab = str_to_tab(map, '\n');
    return (0);
}

int navy_game(navy_t *navy, char **argv, int argc)
{
    char *input;

    link_process(navy, argv[1], argc);
    place_boat(navy->map->arg_tab, navy);
    //print_game(navy);
    signal(16, get_end);
    signal(17, get_end);
    signal(SIGUSR2, get_end);
    while (end_game(navy)) {
        signal(SIGUSR1, get_end);
        if (gameloop(navy, input) == 84)
            continue;
       print_game(navy);
    }
}

int help(int argc, char **argv)
{
    if (argc <= 1 || argc >= 4)
        return (84);
    if (my_strcmp(argv[1], "-h") == 0) {
        print_help();
        return (0);
    }
    return (13);
}

int main(int argc, char **argv)
{
    int return_value = 0;
    navy_t *navy = malloc(sizeof(navy_t));

    navy->map = malloc(sizeof(navy->map));
    navy->player = malloc(sizeof(navy_t));
    return_value = help(argc, argv);
    if (return_value != 13)
        return (return_value);
    navy->playing = argc - 2;
    if (navy_open_read_file(argv, navy, argc) == 84)
        return (84);
    if (error_map(navy) == 84)
        return (84);
    navy_game(navy, argv, argc);
    return (0);
}
