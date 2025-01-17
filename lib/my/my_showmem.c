/*
** EPITECH PROJECT, 2024
** MY_SHOWMEM
** File description:
** Memory dumb
*/
#include "my.h"

static int my_is_printable(char c)
{
    return (c >= 32 && c <= 126);
}

static void print_hex_address(int address)
{
    char hex_address[9];

    for (int i = 7; i >= 0; i--) {
        hex_address[i] = "0123456789abcdef"[address % 16];
        address /= 16;
    }
    hex_address[8] = '\0';
    my_putstr(hex_address);
    my_putstr(": ");
}

static void print_hex_content(char const *str, int size, int line)
{
    int i = line * 16;
    int hex_count = 0;

    for (int j = 0; j < 16 && i < size; i++) {
        if (str[i] < 16) {
            my_putchar('0');
        }
        my_putnbr_base(str[i], "0123456789abcdef");
        if (j % 2 == 1)
            my_putchar(' ');
        hex_count++;
        j++;
    }
    for (; hex_count < 16; hex_count++) {
        my_putstr("  ");
        if (hex_count % 2 == 1)
            my_putchar(' ');
    }
}

static void print_str_content(char const *str, int size, int line)
{
    for (int i = line * 16; i < (line + 1) * 16 && i < size; i++) {
        if (my_is_printable(str[i])) {
            my_putchar(str[i]);
        } else {
            my_putchar('.');
        }
    }
    for (int i = size; i < (line + 1) * 16; i++) {
        my_putchar('.');
    }
}

int my_showmem(char const *str, int size)
{
    int lines = (size + 15) / 16;

    for (int line = 0; line < lines; line++) {
        print_hex_address(line * 16);
        print_hex_content(str, size, line);
        print_str_content(str, size, line);
        my_putchar('\n');
    }
    return 0;
}
