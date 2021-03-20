/*
** EPITECH PROJECT, 2020
** str
** File description:
** islower
*/

int my_str_islower(char const *str)
{
    int i = 0;
    int x = 0;

    for (; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            x += 1;
    if (x == i)
        return (1);
    if (x < i)
        return (0);
}