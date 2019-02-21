/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** convert
*/

#include <malloc.h>
#include "include/convert.h"
#include "include/my.h"

int int_len(int a)
{
    int i = 0;

    for (i; a > 0; i++)
        a /= 2;
    return i;
}

char *substr(char const *str, char separator)
{
    char *new = NULL;
    int i = 0;

    if (!str)
        return (NULL);
    for (; str[i] && str[i] != separator; i++);
    new = malloc((i + 1) * sizeof(char));
    for (int j = 0; j < i; j++)
        new[j] = str[j];
    new[i] = 0;
    return (new);
}

char *convert_to_base(int num, int base)
{
    int len = int_len(num);
    char bases[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *buffer = malloc(sizeof(char) * len * 2 + 2);
    char *convert = malloc(65535);
    int i = 0;

    for (i = 0; num > 0; i++) {
        convert[i] = bases[num % base];
        num /= base;
    }
    convert[i] = '\0';
    my_revstr(convert);
    convert[i] = '\0';
    free(buffer);
    return (convert);
}

int convert_str(char *str)
{
    int len;
    char *buffer = substr(str, '2');
    int i = 0;
    int sum = 0;
    int multiplier = 0;

    len = my_strlen(buffer);
    for (i = len - 1; i >= 0; i--)
        sum += ((buffer[i] - '0') * (1 << multiplier++));
    free(buffer);
    return (sum);
}
