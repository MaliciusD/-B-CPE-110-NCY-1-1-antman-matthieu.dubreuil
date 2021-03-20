/*
** EPITECH PROJECT, 2020
** power
** File description:
** rec
*/

int my_compute_power_rec(int nb, int p)
{
    int res;
    long r_res = res;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    else
        return (r_res = nb * my_compute_power_rec(nb, p - 1));
}
