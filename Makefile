##
## EPITECH PROJECT, 2018
## Makefile libmy
## File description:
## This is my Makefile for my lib
##          make -C ./lib/my  === \n === -I"include" -L"lib/my" -lmy

SRC =	lib/my/my_putchar.c				\
		lib/my/my_put_nbr.c				\
		lib/my/my_putstr.c				\
		lib/my/my_revstr.c				\
		lib/my/my_showmem.c				\
		lib/my/my_showstr.c				\
		lib/my/my_sort_int_array.c		\
		lib/my/my_strcapitalize.c		\
		lib/my/my_strcat.c				\
		lib/my/my_strcmp.c				\
		lib/my/my_strcpy.c				\
		lib/my/my_strlen.c				\
		lib/my/my_strlowcase.c			\
		lib/my/my_getnbr.c				\
		lib/my/my_strncat.c				\
		lib/my/my_strncmp.c				\
		lib/my/my_strncpy.c				\
		lib/my/my_str_to_word_array.c	\
		lib/my/my_strstr.c				\
		lib/my/my_itoa.c				\
		lib/my/get_next_line.c			\
		navy.c							\
		sig.c							\
		convert.c						\
		navy_map.c						\
		navy_print_map.c				\
		error.c							\
		link.c							\
		navy_game.c

OBJ =   $(SRC:.c=.o)

CFLAGS  += -g -I./../../include

NAME    =   navy

RED =   \033[1m\033[38;2;164;0;0m

GREEN   =   \033[1m\033[38;2;100;245;0m

WHITE = \033[0m

BLUE = \033[1m\033[38;2;0;0;170m

$(NAME):    $(OBJ)
		gcc -o $(NAME) $(OBJ) -Wall -W -Wformat-nonliteral -Wcast-align -Wpointer-arith -Wbad-function-cast -Wmissing-prototypes -Wstrict-prototypes -Wmissing-declarations -Winline -Wundef -Wnested-externs -Wcast-qual -Wshadow -Wwrite-strings -Wno-unused-parameter -Wfloat-equal -std=c99 -pedantic
		rm -f *.o

all:    $(NAME)
		@printf " ----------------------------------\n"
		@printf " |$(BLUE)Compilation du Makefile réussie.$(WHITE)|\n"
		@printf " |$(BLUE)-> BINAIRE:$(WHITE) ./%s    |\n" $(NAME)
		@printf " ----------------------------------\n"

clean:
		@rm -f $(OBJ)
		@printf "Les .o ont bien été supprimés.\n"

fclean: clean
		@rm -f $(NAME)
		@printf "La/Le %s a été supprimé.\n" $(NAME)

re:     fclean all

%.o:    %.c
		@echo -en "${BLUE}$@${WHITE} "; $(CC) -c -o $@ $< ${CFLAGS}; if [ $$? -eq 0 ]; then echo -e "${GREEN}[OK]${WHITE}"; else echo -e "${RED}[ERROR]${WHITE}"; fi; echo;
