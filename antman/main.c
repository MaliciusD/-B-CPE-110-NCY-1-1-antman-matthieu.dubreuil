/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** main
*/

#include "include/my.h"

int error_handling(int argc, char *filepath)
{
    if (argc != 3)
        return (84);
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (84);
    struct stat buf;
    stat(filepath, &buf);
    long size = buf.st_size;
    if (size >= 2147483647 || size <= -2147483647)
        return (84);
    char *buffer = malloc(sizeof(char) * size + 1);
    if (buffer == NULL)
        return (84);
    if (read(fd, buffer, size) == -1)
        return (84);
    fd = close(fd);
    free (buffer);
    return (0);
}

int detect_file(char **av, struct_t *ant)
{
    if (av[2][0] == '1' || av[2][0] == '2') {
        ant->txt = 1;
        ant->site = 1;
    }
    if (av[2][0] == '3')
        ant->image = 1;
    if (av[2][0] != '1' && av[2][0] != '2' && av[2][0] != '3')
        return (84);
    return (0);
}

void compare_dico_buffer(struct_t *ant)
{
    int y = 0;
    int len_buffer = my_strlen(ant->buffer);
    int z = 0;
    int w = 0;
    ant->buffer_compressed = malloc(sizeof(char) * (ant->size_buffer * 2));
    ant->buffer_clean = malloc(sizeof(char) * (ant->size_buffer * 2));
    int o = 0;
    int r = 0;
    ant->capte = 0;
    ant->last = 0;
    ant->count = 0;
    compress_char(ant, o, r, y);
    my_printf("%s", ant->buffer_compressed);
}

void create_dico(struct_t *ant)
{
    ant->two_letters = malloc(sizeof(char) * (3));
    int j = 0;

    for (int i = 0; i <= 379; i++) {
        if (ant->buffer_dico[i] != '*' && ant->buffer_dico[i] != '\0') {
            ant->stock_dico[j][0] = ant->buffer_dico[i];
            if (ant->buffer_dico[i + 1] != NULL)
                ant->stock_dico[j][1] = ant->buffer_dico[i + 1];
            j++;
            i++;
        }
    }
    compare_dico_buffer(ant);
}

int main(int ac, char **av)
{
    if (error_handling(ac, av[1]) == 84)
        return (84);
    struct_t *ant = malloc(sizeof(struct_t));
    ant->image = 0;
    if (detect_file(av, ant) == 84)
        return (84);
    set_files(ant, av);
    ant->stock_dico = malloc(sizeof(char *) * (10000));
    for (int i = 0; i < 10000; i++)
        ant->stock_dico[i] = malloc(sizeof(char) * (10000));
    if (ant->image == 0)
        create_dico(ant);
    if (ant->image == 1)
        compimage(ant);
    return (0);
}