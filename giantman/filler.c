/*
** EPITECH PROJECT, 2021
** filler
** File description:
** filler
*/

#include "include/my.h"

void chillman(struct_t *giant)
{
    int c = 0;
    int z = 0;
    for (int i = 0; giant->buffer[i] != '\0'; i++) {
        if (giant->buffer[i] < 0 && giant->buffer[i] >= -127) {
            c = giant->buffer[i] + 127;
            for (int j = 0; giant->dico[c][j] != '\0'; j++, z++)
                giant->buf_uncp[z] = giant->dico[c][j];
        }
        else {
            giant->buf_uncp[z] = giant->buffer[i];
            z++;
        }
    }
    giant->buf_uncp[z] = '\0';
}

void dicpic(struct_t *ant)
{
    int k = 0;
    int j = 0;
    struct stat buf;
    stat("dicpic.txt", &buf);
    ant->strdico = malloc(sizeof(char) * (10000));
    ant->dico = malloc(sizeof(char *) * (10000));
    for (int i = 0; i < 10000; i++)
        ant->dico[i] = malloc(sizeof(char) * (10000));
    int fd = open("dicpic.txt", O_RDONLY);
    int size = buf.st_size;
    read(fd, ant->strdico, size);
    fd = close(fd);
    for (int i = 0; ant->strdico[i] != '@'; i++, k++) {
        if (ant->strdico[i] == '*') {
            j++;
            i++;
            k = 0;
        }
        ant->dico[j][k] = ant->strdico[i];
    }
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

void redorblue(struct_t *giant)
{
    if (giant->image == 1)
        dicpic(giant);
    else
        storedico(giant);
}