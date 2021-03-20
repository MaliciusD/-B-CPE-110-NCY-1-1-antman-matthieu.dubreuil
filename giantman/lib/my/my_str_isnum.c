/*
** EPITECH PROJECT, 2020
** str
** File description:
** isnum
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    int x = 0;

    for (; str[i] != '\0'; i++)
        if (str[i] >= '0' && str[i] <= '9')
            x += 1;
    if (x == i)
        return (1);
    if (x < i)
        return (0);
}