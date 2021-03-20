/*
** EPITECH PROJECT, 2020
** call
** File description:
** functions3
*/

#include <stdarg.h>
#include "../include/my.h"

void func_pointer(va_list ap)
{
    my_put_pointer(va_arg(ap, int));
}