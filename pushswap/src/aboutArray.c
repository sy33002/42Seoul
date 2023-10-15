/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aboutArray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:16:35 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/15 20:52:36 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int isSpace(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == ' ')
            return (1);
        i++;
    }
    return (0);
}

unsigned int splitSize(char **str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

int    arraySize(char **av)
{
    char    **split_str;
    int     i;
    int     len;

    i = 0;
    len = 0;
    while(av[i])
    {
        if (isSpace(av[i]))
        {
            split_str = ft_split(av[i], ' ');
            len += splitSize(split_str);
            freeStr(split_str);
        }
        else
            len++;
        i++;
    }
    return (len - 1);
}

int *numArray(char **av, int size)
{
    char    **split_str;
    int     *nums;
    int     ac_len;
    int     i;
    int     j;

    i = 1;
    ac_len = 0;
    nums = (int *)malloc(sizeof(int) * size);
    if (!nums)
        return (NULL);
    while(av[i])
    {
        j = 0;
        split_str = ft_split(av[i], ' ');
        while(split_str[j])
        {
            nums[ac_len] = ft_atoi(split_str[j]);
            ac_len++;
            j++;
        }
        freeStr(split_str);
        i++;
    }
    return (nums);
}

void    ft_putstr(char *str)
{
    int i;
    
    i = 0;
    if (!str)
        return ;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}