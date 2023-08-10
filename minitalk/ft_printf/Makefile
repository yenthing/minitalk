# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynguyen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 19:50:23 by ynguyen           #+#    #+#              #
#    Updated: 2023/01/02 19:48:26 by ynguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCES	=	ft_printf.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_numbercount.c \
			ft_hexcount.c

NAME	= 	libftprintf.a
OBJECTS	=	$(SOURCES:.c=.o)
CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):
			$(CC) $(CFLAGS) -c $(SOURCES)
			ar rcs $(NAME) $(OBJECTS)

clean:
			$(RM)	$(OBJECTS)

fclean:			clean
			$(RM)	$(NAME)

re:			fclean	$(NAME)

.PHONY:		all clean fclean re
