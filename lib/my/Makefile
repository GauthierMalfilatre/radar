##
## EPITECH PROJECT, 2024
## LYBMY_MAKEFILE
## File description:
## LIBMY MAKEFILE
##

SRC = 	my_strcat.c \
	my_strlowcase.c \
	my_str_isprintable.c \
	my_getnbr.c \
	my_showstr.c \
	my_compute_square_root.c \
	my_strstr.c \
	my_strncat.c \
	my_strlen.c \
	my_str_to_word_array.c \
	my_is_prime.c \
	my_strdup.c \
	my_str_isalpha.c \
	my_swap.c \
	my_compute_power_rec.c \
	my_find_prime_sup.c \
	my_putchar.c \
	my_sort_int_array.c \
	my_getnbr_base.c \
	my_putstr.c \
	my_show_word_array.c \
	my_str_isupper.c \
	my_strcpy.c \
	my_put_nbr.c \
	my_strncmp.c \
	my_strcmp.c \
	my_strncpy.c \
	my_putnbr_base.c \
	my_strcapitalize.c \
	my_revstr.c \
	my_strupcase.c \
	my_str_islower.c \
	my_isneg.c \
	my_showmem.c \
	my_str_isnum.c \
	my_put_float.c \
	my_put_science.c \
	get_index.c \
	printf/get_params.c \
	printf/grenade.c \
	printf/my_printf.c \
	printf/print_fag.c \
	printf/utils/flag_s.c \
	printf/utils/flag_i.c \
	printf/utils/flag_percent.c \
	printf/utils/flag_c.c \
	printf/utils/flag_n.c \
	printf/utils/flag_x.c \
	printf/utils/flag_u.c \
	printf/utils/flag_o.c \
	printf/utils/flag_p.c \
	printf/utils/flag_f.c \
	printf/utils/flag_a.c \
	printf/utils/flag_e.c \
	printf/utils/flag_g.c \
	printf/utils/is_nan.c \
	printf/utils/add_width.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

cc = gcc

all: $(NAME)

$(NAME):  $(OBJ)
	cp my.h ../../include/my.h
	ar rc $(NAME) $(OBJ)
	find . -name "*.o" -delete
	cp libmy.a ../libmy.a

clean:
	find . -name "*~" -delete -o -name "#*#" -delete -o -name "*.out" -delete
	find . -name "*.o" -delete -o -name "unit_tests"  -delete
	find . -name "*.a" -delete -o -name "*.log" -o -name "'#*#'" -delete
	find . -name "*.gcda" -delete -o -name "*.gcno" -delete
	clear
