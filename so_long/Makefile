# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 16:03:30 by jihyuki2          #+#    #+#              #
#    Updated: 2023/11/28 17:38:06 by jihyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
FLAGS		= -Wall -Wextra -Werror 
NAME		= so_long
LIBFT		= libft
PRINTF		= ft_printf
LIBFT_LIB	= libft.a
PRINT_LIB	= ft_printf.a

SRCS		= so_long.c \
			  get_next_line/get_next_line.c \
			  get_next_line/get_next_line_utils.c \
			  ft_printf/ft_printf_ver2.c \
			  ft_printf/ft_printf.c \
			  ft_printf/ft_putnbr.c \
			  ft_printf/ft_str.c \
			  src/error_msg.c \
			  src/pasing/pasing1.c \
			  src/pasing/pasing2.c \
			  src/pasing/pasing3.c \
			  src/set_image/img.c \
			  src/key.c \


OBJS		= $(SRCS:%.c=%.o)
LIBC		= ar rc

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				make -C $(LIBFT) all
				make -C mlx all
				$(CC) -o $(NAME) $(OBJS) -L./libft -lft -L./ft_printf -L./mlx -lmlx -framework OpenGL -framework AppKit

%.o			:	%.c
		$(CC) $(FLAGS) -c $^ -I./ -o $@

clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)
		make clean -C $(PRINTF)
		make -C ./mlx/ clean

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		rm -f $(PRINT_LIB)
		make fclean -C $(LIBFT)

re			:	clean all

.PHONY		:	all clean fclean re