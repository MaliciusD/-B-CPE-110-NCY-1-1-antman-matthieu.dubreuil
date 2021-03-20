/*
** EPITECH PROJECT, 2020
** put
** File description:
** pointer
*/

#include <stdarg.h>
#include "../include/my.h"

void my_put_pointer(unsigned int nb)
{
    int div = 1;
    char *base = "0123456789abcdef";

    my_putstr("0x");
    for (; nb/div > 15; div *= 16);
    for (int i = 0; div > 0; div /= 16) {
        i = nb / div;
        my_putchar(base[i]);
        nb -= (i * div);
    }
}