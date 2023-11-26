# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 16:03:30 by jihyuki2          #+#    #+#              #
#    Updated: 2023/11/26 19:15:30 by jihyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
NAME		= so_long
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= so_long.c \
			  get_next_line/get_next_line.c \
			  get_next_line/get_next_line_utils.c \
			  src/error_msg/error_msg.c \
			  src/pasing/pasing1.c \
			  src/pasing/pasing2.c \
			  src/render_img/img.c \
			  src/key/key.c \


OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror 

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				make -C $(LIBFT) all
				make -C mlx all
				$(CC) -o $(NAME) $(OBJS) -L ./libft -lft -L ./mlx -lmlx -framework OpenGL -framework AppKit

%.o			:	%.c
		$(CC) $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re