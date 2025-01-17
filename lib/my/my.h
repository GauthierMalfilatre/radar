/*
** EPITECH PROJECT, 2024
** MY_H
** File description:
** Header file for all.
*/
#ifndef MY_H
    #define MY_H
    #include <stdarg.h>
// libmy
int my_isneg(int n);
int my_errstr(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *str, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
char *my_strstr2(char *str, char const *to_find);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_putnbr_base(unsigned long int nbr, char const *base);
int my_getnbr_base(char const *str, char const *base);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
int my_putnbr(int nb);
int my_putchar(char c);
int my_nbrlen(long long int nb, int base);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strdup(char const *src);
char *my_strndup(char const *src, int n);
int my_show_word_array(char *const *tab);
char **my_str_to_word_array(char const *str);
int my_free_word_array(char **array);
double my_fmod(double x, double y);
char *convert_base(char const *nbr, char const *base_from,
    char const *base_to);
struct info_param *my_params_to_array(int ac, char **av);
int my_show_param_array(struct info_param const *par);
int get_color(unsigned char red, unsigned char green, unsigned char blue);
char *my_strccat(char *dest, char const c);
int my_putnbr_ll(long long int nb);
int my_putnbr_base_ull(unsigned long long int nbr, char const *base);
int my_putnbr_ull(unsigned long long int nb);
int my_nbrlen_ull(unsigned long long int nb, int base);
long double my_round(long double a, int b);
float my_pow(int nb, int p);
int my_put_float(long double f, int precision);
int my_flen(long double f, int precision);
char *my_strupper(char const *str);
int my_put_science(long double f, int precision, int is_caps);
int my_put_round(long double f, int precision);
int my_putnstr(char const *str, int n);
int my_strnlen(char const *str, int n);
char *my_strrstr(char *str, char const *to_find);
char *my_stradd(char *dest, char *src);
int get_str_index(char **kronk_list, char *kronk_buffer);
double my_getfloat(char const *str);
//int get_index(char const *str, char c);
// printf
int my_printf(char const *format, ...);
int is_char_in(char *flags, char c);
#endif
