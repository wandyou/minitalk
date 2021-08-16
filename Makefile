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

NAME   = server
CLIENT   = client
CC	     = clang
RM		= rm -rf
FLAGS    = -Wall -Werror -Wextra

SRCS = 	srcs/server.c \
		srcs/utils.c

SRCS_CLIENT = srcs/client.c \
			srcs/utils.c

OBJS = $(SRCS:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all :
	make $(NAME)
	make $(CLIENT)

$(NAME) : $(OBJS) includes/minitalk.h
			$(CC) -o $(NAME) $(OBJS) $(FLAGS)
		
$(CLIENT) : $(OBJS_CLIENT) includes/minitalk.h
			$(CC) -o $(CLIENT) $(OBJS_CLIENT) $(FLAGS)

bonus : all

clean :
	$(RM) $(OBJS) $(OBJS_CLIENT)

fclean: clean
	$(RM) $(NAME) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re