/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:37:14 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/15 20:53:40 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    int arr_size;
    
    int *nums = NULL;
    nums = inputParsing(av, &arr_size, nums);
    printf("ac : %d\n", ac);
    printf("------");
    int n = isSpace("asdfasdf");
    printf("%d", n);
    return (0);
}