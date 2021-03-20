/*
** EPITECH PROJECT, 2020
** call
** File description:
** functions2
*/

#include <stdarg.h>
#include "../include/my.h"

void func_binary(va_list ap)
{
    my_put_bin(va_arg(ap, int));
}

void func_hexa(va_list ap)
{
    my_put_hexa(va_arg(ap, int));
}

void func_hexaupper(va_list ap)
{
    my_put_hexauppercase(va_arg(ap, int));
}

void func_octal(va_list ap)
{
    my_put_octal(va_arg(ap, int));
}

void func_percentS(va_list ap)
{
    my_percentS(va_arg(ap, char *));
}