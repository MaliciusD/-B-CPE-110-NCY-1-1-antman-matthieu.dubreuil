/*
** EPITECH PROJECT, 2020
** put
** File description:
** nbr
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    long a = nb;
    if (a == 0)
        my_putchar(0);
    if (a < 0) {
        my_putchar('-');
        a = a * (-1);
    }
    if (a >= 10)
        my_put_nbr(a / 10);
    my_putchar((a % 10) + 48);
}
