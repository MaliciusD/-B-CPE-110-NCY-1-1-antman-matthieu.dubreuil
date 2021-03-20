/*
** EPITECH PROJECT, 2020
** square
** File description:
** root
*/

int my_compute_square_root(int nb)
{
    int res = 0;

    if (nb < 0)
        return (0);
    while ((res * res) != nb) {
        if ((res * res) > nb)
            return (0);
        res++;
    }
    return (res);
}
