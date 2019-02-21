/*
** EPITECH PROJECT, 2018
** include
** File description:
** create an include
*/
#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <malloc.h>
#include <stdio.h>
#include "struct.h"

int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char *str);
int my_isneg(int nb);
int my_is_prime(int nb);
void my_putchar(char c);
void my_put_nbr(int nb);
void my_putstr(char *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char *src);
int my_strcmp(char const *s1, char const *s2);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char dest, char const *src, int nb);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char **str_to_tab(char *str, char separator);
char *my_itoa(int n);
void itoa_isnegative(int *n, int *negative);
int my_getnbr_char(char c);
//--------------------------------------------------------- navy.c
int help(int argc, char **argv);
void print_help(void);
int navy_game(navy_t *navy, char **argv, int argc);
int navy_open_read_file(char **filepath, navy_t *navy, int argc);
//--------------------------------------------------------- link.c
int link_process(navy_t *navy, char *i, int i1);
//--------------------------------------------------------- utils.c
char **str_to_tab(char *str, char separator);
//--------------------------------------------------------- navy_map.c
char *check_user(char **argv, int argc, navy_t *navy);
int is_number(char *str);
int void_map(navy_t *navy);
int check_argue(navy_t *navy);
int check_boat_lengh(char **str, int i);
int convert_str(char *str);
//--------------------------------------------------------- navy_print_map.c
int print_map(char **map);
int place_boat(char **arg, navy_t *navy);
int find_side(char *str, int size, navy_t *navy);
char **place_line(navy_t *navy, char *str);
char **place_column(navy_t *navy, char *str);
//----------------------------------------------------------- error.c
int error_map(navy_t *navy);
int check_input(char *str);
int print_game(navy_t *navy);
int check_ennemy_attack(int pos);
int place_point(char c, int pos, char **map);
//---------------------------------------------------------- navy_game.c
int end_game(navy_t *navy);
char check_hit(int pos, navy_t *navy);
#endif
