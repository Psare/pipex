NAME	=	pipex

SRCS	=	src/pipex.c 	src/pipex_check.c	src/pipex_utils.c

HEADER	=	include/pipex.h

OBJ		=	$(SRCS:%.c=%.o)

LIB		=	lib/libft.a

INCLUDE	=	-I

СС		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		= rm -rf
#---------------------------------------------------------------------------------
RED		=	\033[1;31m
BLUE	=	\033[1;34m
YELLOW	=	\033[1;33m
WHITE	=	\033[1;32m
PUPURE	=	\033[1;35m
GRY		=	\033[1;30m
TURQUOISE =	\033[36;1m
END		=	\033[0m
#---------------------------------------------------------------------------------
.PHONY:		all	clean	fclean	re	bonus	lib

all:		lib $(NAME)

lib:
			@$(MAKE) -C lib/


$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
			@echo "$(TURQUOISE)\n< Complited $(NAME) >\n$(END)"
#			@say compilation of pipex is complited

%.o 	:	%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ)
			@$(MAKE) -C lib/ clean
			@echo "$(PUPURE)\n< Cleaning succeed >\n$(END)"

fclean:		clean
			@$(MAKE) -C lib/ fclean
			@$(RM) $(NAME)
			@echo "$(PUPURE)\n< All created files were deleted >\n$(END)"

re:			fclean all
			@echo "$(PUPURE)\n< Remake done >\n$(END)"


