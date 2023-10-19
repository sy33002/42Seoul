/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:39:03 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/19 21:37:28 by jihyuki2         ###   ########.fr       */
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

int 	isSpace(char *str);
unsigned int splitSize(char **str);
int    	arraySize(char **av);
int 	*numArray(char **av, int size);
void	bigSort(t_info *info);
void	max_top_utils(t_info *info, int *i);
void	max_top(t_info *info);
void	a_to_b(t_info *info, int chunk);
void	b_to_a(t_info *info);
void	isInteger(char **av);
void	isSorted(int *nums, int size);
void	hasDuplicates(int *nums, int size);
int	*	inputParsing(char **av, int *arr_size, int *nums);
void	listAddBackA(t_info *info, t_num **head, int value);
void	listAddBackB(t_info *info, t_num **head, int value);
void	listAddFrontA(t_info *info, int value);
void	listAddFrontB(t_info *info, int value);
void	listRemoveFrontA(t_info *info);
void	listRemoveFrontB(t_info *info);
void	listRemoveBackA(t_info *info);
void	listRemoveBackB(t_info *info);
void	littleSort(t_info *info);
void	threeSort(t_info *info);
int		findIndex(t_info *info, int find);
void	fourSort(t_info *info);
t_num	*newStack(void);
t_num	*newNode(void);
t_info	*newInfo(void);
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);
void	errorMsg(void);
void	freeStr(char **str);
void	arrayTo_Astack(t_info *info, int *array, int size);
void	makeInfoArray(t_info *info, int *nums, int size);
void	arrayTo_Index(t_info *info, int *nums, int arr_size);
void	bubbleSort(int *arr, int size);
void	ft_putstr(char *str);

#endif