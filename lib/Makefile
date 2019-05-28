##
# EPITECH PROJECT, 2018
# makefile
# File description:
# make things
##

SRC	=	number.c	\
		str_to_array.c	\
		str_utils.c	\
		utils_csfml.c	\
		math.c

REDDARK	=	\033[31;2m

RED	=	\033[31;1m

GREEN	=	\033[32;1m

YEL	=	\033[33;1m

BLUE	=	\033[34;1m

PINK	=	\033[35;1m

CYAN	=	\033[36;1m

RES	= \033[0m

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

%.o:	%.c
	@gcc $(CFLAGS) -o $@ -c $<

all: start $(NAME)

$(NAME):	$(OBJ)
	@ar	rc	$(NAME) $(OBJ)
	@ranlib $(NAME)
	@make --no-print-directory clean
	@cp lib.h ../include

start:
	@echo -e " [$(RED)START GCC LIB$(RES)]       $(BLUE)IN WORK$(RES)"

clean:
	@rm -rf $(OBJ)

fclean:	clean
		@rm -rf $(NAME)

re:	fclean	all
