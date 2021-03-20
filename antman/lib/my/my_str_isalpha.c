/*
** EPITECH PROJECT, 2020
** str
** File description:
** isalpha
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    int x = 0;

    for (; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
            x += 1;
    if (x == i)
        return (1);
    if (x < i)
        return (0);
}