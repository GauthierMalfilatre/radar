##
## EPITECH PROJECT, 2024
## DAMIEN
## File description:
## Makefile
##

SRC =	src/radar.c \
		src/create/radar.c \
		src/create/textures.c \
		src/create/scenes.c \
		src/create/medals.c \
		src/create/actor.c \
		src/create/skins.c \
		src/scenes/trafik.c \
		src/scenes/menu.c \
		src/scenes/medals.c \
		src/scenes/pilot.c \
		src/scenes/better_collider.c \
		src/load/skins.c \
		src/load/medals.c \
		src/load/textures.c \
		src/load/scenes.c \
		src/load/check_funcs/check1.c \
		src/load/check_funcs/check2.c \
		src/actors/planes.c \
		src/actors/teapot.c \
		src/actors/towers.c \
		src/utils.c \
		src/utils2.c \
		src/saves.c

OBJ = $(SRC:.c=.o)

NAME = my_radar

CFLAGS = -Wall -g

all: $(NAME)

$(NAME): $(OBj)
	@rm -f include/my.h
	@rm -f include/my_printf.h
	@make -C lib/my > /dev/null
	@gcc -o $(NAME) $(SRC) -Iinclude/ -lcsfml-graphics -lcsfml-window \
	-lcsfml-audio -lcsfml-system -lm -Llib/ -lmy > /dev/null -g -Wall
	@echo "MAKED"

.PHONY: run
run: re
	@echo "RUNNING $(NAME)"
	@./$(NAME) scripts/exemple
	@echo "SUCCESFULLY RUNNED $(NAME)"

.PHONY: debug
debug: re
	@echo "VALGRINDING $(NAME)"
	@valgrind ./$(NAME) scripts/exemple
	@echo "SUCCESFULLY VALGRINDED $(NAME)"

.PHONY: debugall
debugall: re
	@echo "VALGRINDING $(NAME)"
	@valgrind --leak-check=full --track-origins=yes ./$(NAME) scripts/exemple
	@echo "SUCCESFULLY VALGRINDED $(NAME)"

.PHONY: clean
clean:
	@find . -name "*~" -delete -o -name "#*#" -delete -o -name "*.out" -delete
	@find . -name "*.o" -delete -o -name "unit_tests"  -delete > /dev/null
	@find . -name "*.a" -delete -o -name "*.log" -o -name "'#*#'" -delete
	@find . -name "*.gcda" -delete -o -name "*.gcno" -delete > /dev/null
	@find . -name "unit_test" -delete > /dev/null
	@echo "CLEAN"

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)

.PHONY: code
code: fclean
	@coding-style . . > /dev/null
	@cat coding-style-reports.log
	@rm -f coding-style-reports.log
	@echo "CODING-STYLE CHECKED"

.PHONY: push
push: fclean
	@git add .
	@echo "What did you change ?" ; read COMMIT ; git commit -m "$$COMMIT"
	@git push -u origin main

.PHONY: re
re: fclean all

.PHONY: cowsay_%
cowsay_%:
	@echo " -------"
	@echo "| $(*F) |"
	@echo " -------"
	@echo "        \\   ^__^"
	@echo "         \\  (oo)\\_______"
	@echo "            (__)\\       )\\/\\"
	@echo "                ||----w |"
	@echo "                ||     ||"

.PHONY: kronk
kronk:
	@echo "Oh ouais."
