/*
** EPITECH PROJECT, 2024
** FRAG
** File description:
** Frag printf format char * like a grenade frag
** %[$][flags][width][.precision][length modifier]conversion
*/

#include <stdlib.h>
#include "../my.h"
#include "my_printf.h"

static linked_clist_t *new_list(void)
{
    linked_clist_t *new_list = malloc(sizeof(linked_clist_t));

    new_list->data = 0;
    new_list->next = 0;
    return new_list;
}

static void add_node(linked_clist_t **list, void *data)
{
    linked_clist_t *new_node = malloc(sizeof(linked_clist_t));
    linked_clist_t *last_node = *list;

    for (; last_node->next; last_node = last_node->next);
    last_node->next = new_node;
    last_node->data = data;
    new_node->next = (void *) 0;
    return;
}

static flaginfo_t *new_flag(void)
{
    flaginfo_t *new_flag = malloc(sizeof(flaginfo_t));

    return new_flag;
}

static int get_offset_sub(int offset, const char *str, char *conv_specs)
{
    for (int i = 0; conv_specs[i]; i++) {
        if (str[offset] == conv_specs[i]) {
            return offset + 1;
        }
    }
    return 0;
}

int get_offset(const char *str)
{
    static char *conv_specs = "%idcsnpxXoueEfFgGaAm";
    int offset = 1;

    for (; str[offset]; offset++) {
        if (get_offset_sub(offset, str, conv_specs)) {
            return get_offset_sub(offset, str, conv_specs);
        }
    }
    return offset;
}

linked_clist_t *frag(char const *str)
{
    linked_clist_t *list = new_list();
    flaginfo_t *temp;
    int offset;

    for (int i = 0; str[i];) {
        if (str[i] == '%') {
            offset = get_offset(&str[i]);
            temp = str_to_flaginfo(&str[i]);
            i += offset;
            add_node(&list, temp);
            continue;
        }
        temp = new_flaginfo();
        temp->conversion = 0;
        free(temp->flags);
        temp->flags = my_strndup(&str[i], 1);
        add_node(&list, temp);
        i++;
    }
    return list;
}
