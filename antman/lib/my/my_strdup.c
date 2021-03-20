/*
** EPITECH PROJECT, 2020
** my
** File description:
** duplication string
*/

char *my_strdup(char const *src)
{
    char *point;
    int index = 0;
    int length = my_strlen(src);

    point = malloc(length + 1);
    while (src[index] != '\0') {
        point[index] = src[index];
        index = index + 1;
    }
    return (point);
}