# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damarry <damarry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 19:45:59 by damarry           #+#    #+#              #
#    Updated: 2022/03/05 19:28:42 by damarry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIBFT = libft.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

FILES = ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_striteri.c \

FILES_B = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			
OBJS = $(FILES:.c=.o)

OBJBONUS = $(FILES_B:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)
		$(MAKE) $(PARALLEL) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)
			@echo "Libft compiled"

bonus: $(OBJBONUS)
			ar rc $(NAME) $(OBJBONUS)
			@ranlib $(NAME)

%.o: %.c $(LIBFT)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS) $(OBJBONUS) *.h.gch

fclean: clean
		rm -f $(NAME)

re: fclean all
