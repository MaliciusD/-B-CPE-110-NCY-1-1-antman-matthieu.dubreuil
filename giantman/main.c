/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** main
*/

#include "include/my.h"

void uncompress(struct_t *g, int pc)
{
    int c = 0;
    int z = 0;
    for (int i = 0; g->buffer[i] != '\0'; i++) {
        if (g->buffer[i] == '<' && g->buffer[i + 1] == 64) {
                pc = 1;
                i += 2;
        } if (g->buffer[i] == 64 && pc == 1 && g->buffer[i + 1] == '>') {
                pc = 0;
                i += 2;
        } if (g->buffer[i] < 0 && g->buffer[i] >= -127 && pc == 0) {
            c = g->buffer[i] + 127;
            g->buf_uncp[z] = g->dico[c][0];
            z++;
            g->buf_uncp[z] = g->dico[c][1];
            z++;
        } else {
            g->buf_uncp[z] = g->buffer[i];
            z++;
        }
    } g->buf_uncp[z] = '\0';
}

void storedico(struct_t *giant)
{
    int j = 0;
    for (int i = 0; giant->strdico[i] != '8'; i += 3) {
        giant->dico[j][0] = giant->strdico[i];
        giant->dico[j][1] = giant->strdico[i + 1];
        j++;
    }
}

void storing(struct_t *giant)
{
    struct stat buf;
    struct stat buf2;
    stat(giant->filepath, &buf);
    stat(giant->dictionnary, &buf2);
    giant->size_buf = buf.st_size;
    int size_buffer2 = buf2.st_size;
    giant->strdico = malloc(sizeof(char) * size_buffer2 + 1);
    giant->buffer = malloc(sizeof(char) * giant->size_buf + 1);
    giant->buf_uncp = malloc(sizeof(char) * (giant->size_buf * 5));
    giant->dico = malloc(sizeof(char *) * (10000));
    for (int i = 0; i < 10000; i++)
        giant->dico[i] = malloc(sizeof(char) * (10000));
    int fd = open(giant->filepath, O_RDONLY);
    int fd2 = open(giant->dictionnary, O_RDONLY);
    read(fd, giant->buffer, giant->size_buf);
    read(fd2, giant->strdico, size_buffer2);
    fd = close(fd);
    fd2 = close(fd2);
    redorblue(giant);
}

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

int main(int argc, char **argv)
{
    if (error_handling(argc, argv[1]) == 84)
        return (84);
    struct_t *giant = malloc(sizeof(struct_t));
    giant->image = 0;
    giant->filepath = malloc(sizeof(char) * my_strlen(argv[1]));
    giant->filepath = argv[1];
    if (detect_file(argv, giant) == 84)
        return (84);
    giant->dictionnary = malloc(sizeof(char) * 50);
    if (giant->image == 1)
        giant->dictionnary = "dicpic.txt";
    else
        giant->dictionnary = "dico.txt";
    storing(giant);
    if (giant->image == 1)
        chillman(giant);
    else
        uncompress(giant, 0);
    my_printf("%s", giant->buf_uncp);
    return (0);
}