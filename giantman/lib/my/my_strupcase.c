/*
** EPITECH PROJECT, 2020
** str
** File description:
** upcase
*/

char *my_strupcase(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] > 96 && str[i] < 123)
            str[i] = str[i] - 32;
        else
            str[i] = str[i];
    }
    return (str);
}