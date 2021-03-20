/*
** EPITECH PROJECT, 2021
** image cp
** File description:
** image
*/

#include "include/my.h"

int checkdicpic(struct_t *ant, int i)
{
    char *value = malloc(sizeof(char) * 50);
    for (int k = 0; ant->buffer[i] != '\n' && ant->buffer[i] != ' '; k++, i++)
        value[k] = ant->buffer[i];
    if (value[0] == '\0')
        return (0);
    for (int j = 0; ant->dicpic[j][0] != 0; j++) {
        if (my_strcmp(ant->dicpic[j], value) == 0) {
            ant->spotdico = j;
            return (1);
        }
    }
    return (0);
}

void cppic(struct_t *ant)
{
    int j = 0;
    ant->buffer_compressed = malloc(sizeof(char) * ant->sizepic);
    for (int i = 0; i <= ant->sizepic; i++, j++) {
            if (ant->buffer[i] != ' ' && ant->buffer[i] != '\n' &&
            checkdicpic(ant, i - 1) == 1) {
                ant->buffer_compressed[j - 1] = ant->spotdico - 127;
                i += (my_strlen(ant->dicpic[ant->spotdico]) - 1);
            }
        ant->buffer_compressed[j] = ant->buffer[i];
    }
    ant->buffer_compressed[j - 1] = '\0';
}

void storepic(struct_t *ant)
{
    int fd = open(ant->filepath, O_RDONLY);
    struct stat buf;
    stat(ant->filepath, &buf);
    ant->sizepic = buf.st_size;
    ant->buffer = malloc(sizeof(char) * (ant->sizepic * 2));
    read(fd, ant->buffer, ant->sizepic);
    fd = close(fd);
}

void dicpic(struct_t *ant)
{
    int k = 0;
    int j = 0;
    struct stat buf;
    stat("dicpic.txt", &buf);
    ant->strdicpic = malloc(sizeof(char) * (10000));
    ant->dicpic = malloc(sizeof(char *) * (10000));
    for (int i = 0; i < 10000; i++)
        ant->dicpic[i] = malloc(sizeof(char) * (10000));
    int fd = open("dicpic.txt", O_RDONLY);
    int size = buf.st_size;
    read(fd, ant->strdicpic, size);
    fd = close(fd);
    for (int i = 0; ant->strdicpic[i] != '@'; i++, k++) {
        if (ant->strdicpic[i] == '*') {
            j++;
            i++;
            k = 0;
        }
        ant->dicpic[j][k] = ant->strdicpic[i];
    }
}

void compimage(struct_t *ant)
{
    dicpic(ant);
    storepic(ant);
    cppic(ant);
    my_printf("%s", ant->buffer_compressed);
}