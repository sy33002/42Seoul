/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:39:03 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/15 20:54:48 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_num 
{
	int				num;
	struct s_num 	*next;
}				t_num;

typedef struct s_info 
{
	struct s_num	*a_head;
	struct s_num	*a_top;
	int				a_bottom_num;
	int				a_size;
	struct s_num	*b_head;
	struct s_num	*b_top;
	int				b_bottom_num;
	int				b_size;
	int				*array;
}				t_info;

void    isInteger(char **av);
void    isSorted(int *nums, int size);
void	hasDuplicates(int *nums, int size);
int *inputParsing(char **av, int *arr_size, int *nums);
int isSpace(char *str);
unsigned int splitSize(char **str);
int    arraySize(char **av);
int *numArray(char **av, int size);
void    ft_putstr(char *str);
void errorMsg(void);
void freeStr(char **str);



#endif