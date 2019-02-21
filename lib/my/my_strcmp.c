/*
** EPITECH PROJECT, 2018
** cmp
** File description:
** cmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int	i = 0;

    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
        i = i + 1;
    return (s1[i] - s2[i]);
}
