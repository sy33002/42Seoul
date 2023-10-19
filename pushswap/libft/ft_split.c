/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:47:41 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/19 21:10:10 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charset(char a, char c)
{
	if (a == c)
		return (1);
	return (0);
}

int	ft_countword(char *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] && ft_charset(str[i], c) == 1)
			i++;
		if (str[i] && ft_charset(str[i], c) == 0)
		{
			while (str[i] && ft_charset(str[i], c) == 0)
				i++;
		cnt++;
		}
	}
	return (cnt);
}

int	ft_countlen(char *str, char c, int j)
{
	int	len;

	len = 0;
	while (str[j] && ft_charset(str[j], c) == 0)
	{
		j++;
		len++;
	}
	return (len);
}

char	**ft_split2(char const *s, char c, char **res, int i)
{
	int	j;
	int	k;

	j = 0;
	while (s[j])
	{
		while (s[j] && ft_charset(s[j], c) == 1)
				j++;
		if (s[j])
		{
			k = 0;
			res[i] = (char *)malloc(ft_countlen((char *)s, c, j) + 1);
			if (!res)
				return (NULL);
			while (s[j] && ft_charset(s[j], c) == 0)
				res[i][k++] = s[j++];
			res[i][k] = '\0';
			i++;
		}
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	j = 0;
	res = (char **)malloc(sizeof(char *) * (ft_countword((char *)s, c) + 1));
	if (!res)
		return (NULL);
	res = ft_split2(s, c, res, i);
	while (i--)
	{
		if (res[i] == 0)
			free(res);
	}
	return (res);
}
