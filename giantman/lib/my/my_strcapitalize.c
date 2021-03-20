/*
** EPITECH PROJECT, 2020
** str
** File description:
** capitalize
*/

char *my_strcapitalize(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[0] > 96 && str[0] < 123)
            str[0] = str[0] - 32;
        if (str[i] == ' ' && str[i + 1] > 96 && str[i + 1] < 123)
            str[i + 1] = str[i + 1] - 32;
        if (str[i] > 47 && str[i] < 58 && str[i + 1] > 64 && str[i + 1] < 91)
            str[i + 1] = str[i + 1] + 32;
        if (str[i] > 64 && str[i] < 91 && str[i - 1] > 96 && str[i - 1] < 123)
            str[i] = str[i] + 32;
        if (str[i] == 45 || str[i] == 43 && str[i + 1] > 96 && str[i + 1] < 123)
            str[i + 1] = str[i + 1] -32;
        else
            str[i] = str[i];
    }
    return (str);
}