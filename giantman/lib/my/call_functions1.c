/*
** EPITECH PROJECT, 2020
** call
** File description:
** functions1
*/

#include <stdarg.h>
#include "../include/my.h"

void func_char(va_list ap)
{
    my_putchar(va_arg(ap, int));
}

void func_string(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}

void func_nbr(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

void func_percent(va_list ap)
{
    my_putchar('%');
}

void func_unsignedint(va_list ap)
{
    my_put_unsint(va_arg(ap, int));
}