/*
** EPITECH PROJECT, 2020
** getnbr
** File description:
** getnbf
*/

int my_getnbr(char const *str)
{
    int signe = 0;
    int i = 0;
    int res = 0;

    for (; str[i] >= '0' && str[i] <= '9' || str[i] == '-'; i++)
        if (str[i] == '-')
            signe += 1;
        else
            res = res * 10 + str[i] - 48;
    if (signe % 2 == 1)
        res = res * (-1);
    return (res);
}