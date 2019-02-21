/*
** EPITECH PROJECT, 2018
** sig
** File description:
**
*/
#include <signal.h>
#include <unistd.h>
#include "include/sig.h"
#include "include/get_next_line.h"
#include "include/my.h"

void get_signal(int i)
{
    static int j = 0;

    if (i == SIGUSR1) {
        message[j] = '0';
        j++;
    } else if (i == SIGUSR2) {
        message[j] = '1';
        j++;
    }
    if (i == 16) {
        write(1, "\nenemy connected\n", 17);
        for (; j < 16; j++)
            message[j] = '2';
        j = 0;
    }
}

void get_sig2(int i)
{
    if (i == SIGUSR1) {
        write(1, "successfully connected\n", 23);
        message[0] = 1;
    }
}

void get_end(int i)
{
    static int j = 0;

    if (i == SIGUSR1) {
        message[j] = '0';
        j++;
    } else if (i == SIGUSR2) {
        message[j] = '1';
        j++;
    }
    else if (i == 16) {
        for (; j < 16; j++)
            message[j] = '2';
        j = 0;
    }
}

int gameloop(navy_t *navy, char *input)
{
    int pos;
    char hit;

    if (!navy->playing) {
        message[15] = 0;
        my_putstr("attack: ");
        input = get_next_line(0);
        input[0] -= 16;
        input[1] -= 1;
        if (check_ennemy_attack(my_getnbr(input))) {
            my_putstr("wrong position\n");
            return (84);
        }
        send_message(navy, my_getnbr(input));
        navy->playing = 1;
        while (message[15] == 0);
        printf("%s\n", message);
        if(message[0] == 1) {
            hit = 'x';
            my_putstr("hit");
        } else if(message[0] == 0) {
            hit = 'o';
            my_putstr("miss");
        }
        place_point(hit, my_getnbr(input), navy->map->map_player);
        message[15] = 0;
    } else {
        while (message[15] == 0);
        pos = convert_str(message);
        hit = check_hit(pos, navy);
        hit == 'x' ? send_message(navy, 123) : send_message(navy, 321);
        place_point(hit, pos, navy->map->map_player);
        navy->playing = 0;
    }
}
