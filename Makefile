# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nathanlafarge <nathanlafarge@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 14:05:10 by nathanlafar       #+#    #+#              #
#    Updated: 2021/07/17 20:03:41 by nathanlafar      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = server
CLIENT   = client
CC	     = gcc
FLAGS    = -Wall -Werror -Wextra

all : $(SERVER) $(CLIENT) clean

$(SERVER) : srcs/server.o srcs/utils.o includes/minitalk.h
	@$(CC) server.o utils.o -o $@

$(CLIENT) : srcs/client.o srcs/utils.o includes/minitalk.h
	@$(CC) client.o utils.o -o $@

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I includes

clean :
	@rm -f *.o

fclean: clean
	@rm -f $(SERVER) $(CLIENT)

re: fclean all