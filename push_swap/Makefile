# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 15:37:56 by jihyuki2          #+#    #+#              #
#    Updated: 2023/11/03 20:44:17 by jihyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME		= push_swap
LIBFT		= libft
LIBFT_LI	= libft.a

SRCS		=	push_swap.c \
					./src/about_array.c \
					./src/big_sort.c \
					./src/input_parsing.c \
					./src/list_add.c \
					./src/list_remove.c \
					./src/little_sort.c \
					./src/new.c \
					./src/rr.c \
					./src/rrr.c \
					./src/ss.c \
					./src/utils.c \
					./src/utils2.c \
					./src/utils3.c \
			
OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

CFLAGS		= -Wall -Wextra -Werror -g

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		$(CC) -o $(NAME) $(OBJS) -Llibft -lft

%.o			:	%.c
		$(CC) $(CFLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LI)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re