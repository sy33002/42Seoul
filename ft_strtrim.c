/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:42:51 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/05/06 16:55:52 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkset(char const	*setchar, char const	s1)
{
	int	i;

	i = 0;
	while (setchar[i])
	{
		if (s1 == setchar[i])
			return (1);
		i++;
	}
	return (-1);
}

char	*up_ft_strdup(unsigned int i, unsigned int j, char const	*s1)
{
	char	*tmp;
	int		k;

	k = 0;
	tmp = (char *)malloc(j - i + 1);
	if (!tmp)
		return (NULL);
	while (i < j)
		tmp[k++] = s1[i++];
	tmp[k] = '\0';
	return (tmp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (set[0] == '\0')
		return (ft_strdup((char *)s1));
	if (s1[0] == '\0')
		return (ft_strdup(s1));
	while (s1[i] && checkset(set, s1[i]) == 1)
		i++;
	while (checkset(set, s1[j]) == 1 && i <= j)
		j--;
	j++;
	return (up_ft_strdup(i, j, (char *)s1));
}
