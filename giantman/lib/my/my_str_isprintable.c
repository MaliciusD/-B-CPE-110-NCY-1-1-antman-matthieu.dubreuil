/*
** EPITECH PROJECT, 2020
** str
** File description:
** isprintable
*/

int my_str_isprintable(char const *str)
{
    int i = 0;
    int x = 0;

    for (; str[i] != '\0'; i++)
        if (str[i] >= '\0' && str[i] <= ' ' && str[i] != 127)
            x += 1;
    if (x == i)
        return (0);
    if (x < i)
        return (1);
}