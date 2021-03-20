/*
** EPITECH PROJECT, 2020
** put
** File description:
** base
*/

#include <stdarg.h>
#include "../include/my.h"

void my_put_bin(unsigned int nb)
{
    int div = 1;
    char *base = "01";

    for (; nb/div > 1; div *= 2);
    for (int i = 0; div > 0; div /= 2) {
        i = nb / div;
        my_putchar(base[i]);
        nb -= (i * div);
    }
}

void my_put_hexa(unsigned int nb)
{
    int div = 1;
    char *base = "0123456789abcdef";

    for (; nb/div > 15; div *= 16);
    for (int i = 0; div > 0; div /= 16) {
        i = nb / div;
        my_putchar(base[i]);
        nb -= (i * div);
    }
}

void my_put_hexauppercase(unsigned int nb)
{
    int div = 1;
    char *base = "0123456789ABCDEF";

    for (; nb/div > 15; div *= 16);
    for (int i = 0; div > 0; div /= 16) {
        i = nb / div;
        my_putchar(base[i]);
        nb -= (i * div);
    }
}

void my_put_octal(unsigned int nb)
{
    int div = 1;
    char *base = "01234567";

    for (; nb/div > 7; div *= 8);
    for (int i = 0; div > 0; div /= 8) {
        i = nb / div;
        my_putchar(base[i]);
        nb -= (i * div);
    }
}

void my_percentS(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 10 && str[i] < 32 || str[i] >= 127)
            my_putstr("\\00");
        if (str[i] < 100 && str[i] >= 10 && str[i] < 32 || str[i] >= 127)
            my_putstr("\\0");
        if (str[i] > 100 && str[i] < 32 || str[i] >= 127)
            my_putchar('\\');
        if (str[i] < 32 || str[i] >= 127) {
            my_put_octal(str[i]);
            i++;
        }
        my_putchar(str[i]);
    }
}