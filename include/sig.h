/*
** EPITECH PROJECT, 2018
** sig
** File description:
**
*/
#ifndef NAVY_SIG_H
#define NAVY_SIG_H

#include "struct.h"

extern char message[16];

void get_signal(int i);

void get_sig2(int i);

void send_message(navy_t *navy, int msg_i);

int gameloop(navy_t *navy, char *input);

void get_end(int i);

#endif //NAVY_SIG_H
