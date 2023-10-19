# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 15:37:56 by jihyuki2          #+#    #+#              #
#    Updated: 2023/10/19 19:51:04 by jihyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		=	push_swap.c \
					./src/aboutArray.c \
					./src/bigSort.c \
					./src/inputParsing.c \
					./src/listAdd.c \
					./src/listRemove.c \
					./src/littleSort.c \
					./src/new.c \
					./src/rr.c \
					./src/rrr.c \
					./src/ss.c \
					./src/utils.c \
					./src/utils2.c \

			
OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror -g

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		gcc -o $(NAME) $(OBJS) -Llibft -lft

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re