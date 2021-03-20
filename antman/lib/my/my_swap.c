/*
** EPITECH PROJECT, 2020
** swap
** File description:
** swap
*/

#include <unistd.h>

void my_swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
