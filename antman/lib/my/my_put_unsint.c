/*
** EPITECH PROJECT, 2020
** put
** File description:
** unsint
*/

#include "../include/my.h"

void my_put_unsint(unsigned int nb)
{
    if (nb == 0)
        my_putchar(0);
    if (nb >= 10)
        my_put_unsint(nb / 10);
    my_putchar((nb % 10) + 48);
}