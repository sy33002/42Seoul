/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:39:03 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/11/03 21:25:19 by jihyuki2         ###   ########.fr       */
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
	struct s_num	*next;
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

int		contain_space(char *str);
int		count_size(char **str);
int		array_size(char **av);
int		*av_to_nums(char **av, int size);
void	bigger_sort(t_info *info);
void	rotate_to_max(t_info *info, int *c);
void	find_max_top(t_info *info);
void	move_a_to_b(t_info *info, int chunk);
void	validate_int(char **av);
void	is_sorted(int *nums, int size);
void	has_duplicates(int *nums, int size);
int		*input_parsing(char **av, int *arr_size, int *nums);
void	list_add_front_a(t_info *info, int value);
void	list_add_front_b(t_info *info, int value);
void	list_add_back_a(t_info *info, t_num **head, int value);
void	list_add_back_b(t_info *info, t_num **head, int value);
void	list_remove_front_a(t_info *info);
void	list_remove_front_b(t_info *info);
void	list_remove_back_a(t_info *info);
void	list_remove_back_b(t_info *info);
void	little_sort(t_info *info);
void	three_sort(t_info *info);
int		find_index(t_info *info, int find);
void	four_sort(t_info *info);
void	five_sort(t_info *info);
t_num	*new_stack(void);
t_num	*new_node(void);
t_info	*new_info(void);
void	ra(t_info *info, char *str);
void	rb(t_info *info, char *str);
void	rr(t_info *info);
void	rra(t_info *info, char *str);
void	rrb(t_info *info, char *str);
void	rrr(t_info *info);
void	sa(t_info *info, char *str);
void	sb(t_info *info, char *str);
void	ss(t_info *info);
void	pa(t_info *info, char *str);
void	pb(t_info *info, char *str);
void	error(void);
void	string_free(char **str);
void	array_to_astack(t_info	*info, int *array, int size);
void	make_info_array(t_info *info, int *nums, int size);
void	array_to_index(t_info *info, int *nums, int arr_size);
void	ft_putstr(char *str);
void	bubble_sort(int *arr, int size);
void	stack_free(t_num **stack);
void	check_all_space(char **av);
int		ft_atoi2(const char *str);
int		checkss(int minor, long long res, const char *str, int i);

#endif