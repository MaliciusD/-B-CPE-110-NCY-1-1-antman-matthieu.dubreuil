/*
** EPITECH PROJECT, 2020
** fucntion
** File description:
** my_printf
*/

#include <stdarg.h>
#include "../include/my.h"

int check_flags(char src, va_list ap)
{
    int i = 0;

    while (flags[i].str != '\0') {
        if (flags[i].str == src) {
            flags[i].func(ap);
        } i++;
    }
    return (0);
}

void my_printf(char *src, ...)
{
    int i = 0;
    int j = 0;
    int res;
    va_list ap;
    va_start(ap, src);
    for (i = 0; src[i] != '\0'; i++) { if (src[i] == '%') {
            if (src[i + 1] == '+' || src[i + 1] == '-' ||
            src[i + 1] >= '0' && src[i + 1] <= '9') {
                j  = i + 1;
                while ( src[j] == '+' || src[j] == '-'
                || src[j] >= '0' && src[j] <= '9')
                    j++;
                check_flags(src[j], ap);
                i++;
            } else {
                check_flags(src[i + 1], ap);
                i++;
            } } else
            my_putchar(src[i]);
    } va_end(ap);
}