/*
** EPITECH PROJECT, 2020
** str
** File description:
** isupper
*/

int my_str_isupper(char const *str)
{
    int i = 0;
    int x = 0;

    for (; str[i] != '\0'; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            x += 1;
    if (x == i)
        return (1);
    if (x < i)
        return (0);
}