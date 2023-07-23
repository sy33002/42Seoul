# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 16:36:37 by jihyuki2          #+#    #+#              #
#    Updated: 2023/07/12 20:21:26 by jihyuki2         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #


NAME	= libftprintf.a

SRCS	= ft_printf.c		\
		  ft_printf_ver2.c	\
		  ft_putnbr.c		\
		  ft_str.c			\

CC		= cc

CFLAG	= -Wall -Wextra -Werror

OBJS	= $(SRCS:.c=.o)

INCLUDES= ./ft_printf.h

all		:	$(NAME)

.o		:	.c
			$(CC) $(CFLAG) -c $< -o $@

$(NAME)	:	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re