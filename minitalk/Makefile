# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 17:25:52 by jihyuki2          #+#    #+#              #
#    Updated: 2023/08/27 18:19:13 by jihyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIX: .c.o

CC = gcc

CFLAGS = -Wall -Wextra -Werror
SRCS_SERVER = utils1.c utils2.c server.c
SRCS_CLIENT = utils1.c utils2.c client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

NAME_SERVER = server
NAME_CLIENT = client

all : $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER) : $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $@

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all