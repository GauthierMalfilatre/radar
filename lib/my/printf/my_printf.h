/*
** EPITECH PROJECT, 2024
** MY_PRINTF
** File description:
** Header file for my_printf.c
*/
#ifndef MY_PRINTF_H
    #define MY_PRINTF_H
    #include <stdarg.h>
    #define ABS(value) (((((value) >= 0) ? (value) : (-(value)))))

// printf
typedef int (*ptr_t)();

typedef struct func_pointers_s {
    char chr;
    int (*pointfn)();
} func_pointers_t;

typedef struct flaginfo_s {
    char *flags;
    int width;
    int precision;
    char *length_modifier;
    char conversion;
} flaginfo_t;

typedef struct linked_list_s {
    void *data;
    void *next;
} linked_clist_t;

// Base puts
int my_print_flag_s(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_i(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_d(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_u(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_o(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_c(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_percent(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_n(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_m(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_p(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_x(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_a(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_capsa(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_e(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_capse(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_f(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_capsf(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_g(flaginfo_t *flaginfo, va_list list, int *sum);
int my_print_flag_capsg(flaginfo_t *flaginfo, va_list list, int *sum);

char *get_weird(long double a);
flaginfo_t *new_flaginfo(void);

int my_printf(char const *format, ...);
linked_clist_t *frag(char const *str);
void printf_ag(const flaginfo_t *flaginfo, va_list argv, int *sum);

flaginfo_t *str_to_flaginfo(char const *format);

int is_char_in(char *flags, char c);
int add_width(flaginfo_t *flag, int len, int is_last, long long int nb);
#endif
