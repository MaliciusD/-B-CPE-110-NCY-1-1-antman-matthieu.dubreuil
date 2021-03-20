/*
** EPITECH PROJECT, 2021
** func
** File description:
** func
*/

#include "include/my.h"

void set_files(struct_t *ant, char **av)
{
    struct stat buf;
    struct stat buf2;
    int op = open(av[1], O_RDONLY);
    int op2 = open("dico.txt", O_RDONLY);
    int size_buffer2 = 0;
    int a = 0;
    int b = 0;
    ant->filepath = malloc(sizeof(char) * (10000));
    ant->filepath = av[1];
    stat(av[1], &buf);
    stat("dico.txt", &buf2);
    ant->size_buffer = buf.st_size;
    size_buffer2 = buf2.st_size;
    if (ant->size_buffer == 0)
        return (0);
    ant->buffer_dico = malloc(sizeof(char) * (10000));
    ant->buffer = malloc(sizeof(char) * (ant->size_buffer + 1));
    a = read(op, ant->buffer, ant->size_buffer);
    b = read(op2, ant->buffer_dico, size_buffer2);
}

void compress_char(struct_t *ant, int o, int r, int y)
{
    for (int i = 0; ant->buffer[i] != '\0'; i++) {
        o = ant->buffer[i];
        if (o < 0)
            r = put_balise(ant, r, i);
        else {
            ant->buffer_clean[r] = ant->buffer[i];
            r++;
        }
    }
    for (int i = 0; ant->buffer_clean[i] != '\0'; i++) {
        check_char(ant, i);
        if (ant->count == 1) {
            ant->buffer_compressed[y] = ant->u;
            y++;
            i++;
        } else {
            ant->buffer_compressed[y] = ant->buffer_clean[i];
            y++;
        }
        ant->count = 0; }
}

void check_char(struct_t *ant, int i)
{
    ant->two_letters[0] = ant->buffer_clean[i];
    if (ant->buffer_clean[i + 1] != '\0')
        ant->two_letters[1] = ant->buffer_clean[i + 1];
    if (ant->two_letters[0] == '<') {
        if (ant->two_letters[1] == '@') {
            ant->counter = 1;
        }
    } if (ant->two_letters[0] == '@') {
        if (ant->two_letters[1] == '>') {
            ant->counter = 0;
        }
    }
    for (int j = 0; ant->stock_dico[j][0] != '\0' && ant->count != 1; j++) {
        if (ant->two_letters[0] == ant->stock_dico[j][0] &&
        ant->two_letters[1] == ant->stock_dico[j][1] && ant->counter == 0) {
            ant->count = 1;
            ant->u = j - 127;
        } else {
            ant->count = 0;
            ant->u = 0;
        } }
}

int put_balise(struct_t *ant, int r, int i)
{
    if (ant->capte == 0) {
        ant->buffer_clean[r] = '<';
        r++;
        ant->buffer_clean[r] = '@';
        r++;
        ant->capte = 1;
    } if (ant->capte == 1) {
        ant->buffer_clean[r] = ant->buffer[i];
        r++;
        if (ant->buffer[i + 1] >= 0)
            ant->last = 1;
    } if (ant->capte == 1 && ant->last == 1) {
        ant->buffer_clean[r] = '@';
        r++;
        ant->buffer_clean[r] = '>';
        r++;
    } if (ant->buffer[i + 1] >= 0) {
        ant->capte = 0;
        ant->last = 0;
    } return (r);
}