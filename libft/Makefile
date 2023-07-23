# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 15:40:55 by jihyuki2          #+#    #+#              #
#    Updated: 2023/05/07 18:05:21 by jihyuki2         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

AR = ar
ARFLAGS = crs
RM = rm -rf
INCLUDES = ./libft.h
SRCS_NM =	ft_atoi.c		\
			ft_bzero.c		\
			ft_calloc.c		\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_itoa.c		\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memcpy.c 	\
			ft_memmove.c	\
			ft_memset.c		\
			ft_putchar_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\
			ft_substr.c		\
			ft_striteri.c	\
			ft_strjoin.c	\
			ft_strchr.c		\
			ft_strdup.c		\
			ft_strlcat.c	\
			ft_strlcpy.c	\
			ft_strlen.c		\
			ft_strmapi.c	\
			ft_strncmp.c	\
			ft_strnstr.c	\
			ft_strrchr.c	\
			ft_strtrim.c	\
			ft_tolower.c	\
			ft_toupper.c 	\
			ft_split.c		\
			
SRC_BO =	ft_lstnew.c			\
			ft_lstadd_back.c 	\
			ft_lstadd_front.c	\
			ft_lstclear.c		\
			ft_lstdelone.c		\
			ft_lstiter.c		\
			ft_lstlast.c		\
			ft_lstmap.c			\
			ft_lstsize.c		\

OBJ = $(SRCS_NM:.c=.o)

OBJ_BONUS = $(SRC_BO:.c=.o)

ifdef WITH_BONUS
		OBJ_FILES = $(OBJ) $(OBJ_BONUS)
	else
		OBJ_FILES = $(OBJ)
endif

all : $(NAME)

.c.o : $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJ_FILES)
	$(AR) $(ARFLAGS) $@ $^

clean :
	$(RM) $(RMFLAG) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(RMFLAG) $(NAME)

re: fclean all

bonus :
	@make "WITH_BONUS=1" all
