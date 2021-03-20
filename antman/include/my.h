/*
** EPITECH PROJECT, 2020
** headers
** File description:
** headers
*/

#ifndef my_h
#define my_h

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <string.h>
#include <getopt.h>

void my_put_bin(unsigned int nb);
void my_put_hexa(unsigned int nb);
void my_put_hexauppercase(unsigned int nb);
void my_put_octal(unsigned int nb);
void my_percentS(char *str);
void my_put_pointer(unsigned int nb);
void func_char(va_list ap);
void func_string(va_list ap);
void func_nbr(va_list ap);
void func_percent(va_list ap);
void func_unsignedint(va_list ap);
void func_binary(va_list ap);
void func_hexa(va_list ap);
void func_hexaupper(va_list ap);
void func_octal(va_list ap);
void func_percentS(va_list ap);
void func_pointer(va_list ap);

typedef struct struct_s
{
    char *filepath;
    char *strdicpic;
    char **dicpic;
    char **stock_dico;
    char *buffer_dico;
    char *buffer;
    char *two_letters;
    char *buffer_compressed;
    char *buffer3;
    int spotdico;
    int sizepic;
    int site;
    int txt;
    int image;
    int size_buffer;
    int counter;
    char *buffer_clean;
    int capte;
    int count;
    int last;
    int j;
    int u;
} struct_t;

void set_files(struct_t *ant, char **av);
void compress_char(struct_t *ant, int o, int r, int y);
void check_char(struct_t *ant, int i);
int put_balise(struct_t *ant, int r, int i);
void my_put_unsint(unsigned int nb);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
void my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);

#endif