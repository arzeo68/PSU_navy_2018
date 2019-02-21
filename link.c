/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** link.c
*/
#include <zconf.h>
#include "include/struct.h"
#include "include/my.h"
#include "include/convert.h"
#include "include/sig.h"
#include <signal.h>

char message[16] = {0};

void send_message(navy_t *navy, int msg_i)
{
    char *msg = convert_to_base(msg_i, 2);

    signal(SIGUSR1, get_sig2);
    for (int i = 0; msg[i]; i++) {
        msg[i] == '1' ? kill(navy->pid, SIGUSR2) :
        (msg[i] == '0' ? kill(navy->pid, SIGUSR1) : 0);
        usleep(100);
    }
    usleep(100);
    kill(navy->pid, 16);
}

int link_process(navy_t *navy, char *string, int argc)
{
    char *pid_c = my_itoa(getpid());

    navy->pid = argc == 3 ? my_getnbr(string) : 0;
    write(1, "my_pid: ", 8);
    write(1, pid_c, my_strlen(pid_c));
    write(1, "\n", 1);
    signal(SIGUSR1, get_signal);
    signal(SIGUSR2, get_signal);
    if (!navy->pid) {
        write(1, "waiting for enemy connection...\n", 32);
        signal(16, get_signal);
        while (message[15] == 0);
        navy->pid = convert_str(message);
        kill(navy->pid, SIGUSR1);
    } else {
        send_message(navy, getpid());
        return message[0] == 1 ? 0 : 1;
    }
    return 0;
}