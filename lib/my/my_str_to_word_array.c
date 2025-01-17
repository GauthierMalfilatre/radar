/*
** EPITECH PROJECT, 2024
** MY_STR_TO_WORD_ARRAY
** File description:
** Split a string
*/
#include <stdlib.h>
#include "my.h"

static int is_alphanum(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9') || c == '.');
}

static int count_occ(char const *str)
{
    int i = 0;
    int length = 0;

    for (; str[i]; i++) {
        if ((!i && is_alphanum(str[i])) || (i && is_alphanum(str[i]))
            && !is_alphanum(str[i - 1])) {
            length++;
        }
    }
    return length;
}

static int cust_len(char *str)
{
    int i = 0;

    for (; is_alphanum(str[i]); i++);
    return i;
}

char **my_str_to_word_array(char const *str)
{
    int str_word = count_occ(str);
    char *temp2 = my_strdup(str);
    char *temp = temp2;
    char **dest = malloc(sizeof(char *) * (str_word + 1));
    int size = 0;

    for (int i = 0; i < str_word; i++) {
        while (!is_alphanum(temp[0])) {
            temp++;
        }
        size = cust_len(temp);
        dest[i] = malloc(sizeof(char) * (size + 1));
        my_strncpy(dest[i], temp, size);
        temp += size;
    }
    dest[str_word] = (void *) 0;
    free(temp2);
    return dest;
}

int my_free_word_array(char **array)
{
    for (int i = 0; array[i]; i++) {
        free(array[i]);
    }
    free(array);
    return 0;
}
