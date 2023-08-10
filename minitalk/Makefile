# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynguyen <ynguyen@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 18:20:20 by ynguyen           #+#    #+#              #
#    Updated: 2023/03/24 15:47:37 by ynguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all server client bonus

all: server client bonus

server: server.c
	(cd libft && make)
	(cd ft_printf && make)
	$(CC) $(CFLAGS) -c server.c
	$(CC) $(CFLAGS) -o server server.o ft_printf/libftprintf.a libft/libft.a

client: client.c 
	(cd libft && make)
	(cd ft_printf && make)
	$(CC) $(CFLAGS) -c client.c
	$(CC) $(CFLAGS) -o client client.o ft_printf/libftprintf.a libft/libft.a
	
bonus: client_bonus.c server_bonus.c
	(cd libft && make)
	(cd ft_printf && make)
	$(CC) $(CFLAGS) -c client_bonus.c
	$(CC) $(CFLAGS) -o client_bonus client_bonus.o ft_printf/libftprintf.a libft/libft.a
	$(CC) $(CFLAGS) -c server_bonus.c
	$(CC) $(CFLAGS) -o server_bonus server_bonus.o ft_printf/libftprintf.a libft/libft.a
	
clean:	
	rm -f client.o server.o client_bonus.o server_bonus.o 
	(cd libft && make fclean)
	(cd ft_printf && make fclean)

fclean: clean
	rm -f libft.a libftprintf.a client server client_bonus server_bonus
	
re:	fclean all

