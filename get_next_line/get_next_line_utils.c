/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:57:30 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/08/06 14:53:03 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int		s1_len;
	unsigned int		s2_len;
	char				*tmp;
	int					i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	tmp = (char *)malloc(s1_len + s2_len + 1);
	if (!tmp)
		return (NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		tmp[s1_len++] = s2[i++];
	tmp[s1_len] = '\0';
	return (tmp);
}

char	*ft_strchr(char *str, int c)
{
	int		i;
	char	f;

	i = 0;
	f = (char)c;
	while (str[i])
	{
		if (f == str[i])
			return (str + i);
		i++;
	}
	if (f == str[i])
		return (str + i);
	return (NULL);
}

char	*ft_substr(char *s, int start, int len)
{
	int		l;
	int		i;
	char	*res;

	i = 0;
	if (!s)
		return (NULL);
	else if ((unsigned int)start >= ft_strlen(s))
	{
		res = malloc(1);
		res[0] = 0;
		return (res);
	}
	l = start;
	while (l < len + start && s[l] != '\0')
		l++;
	res = (char *)malloc(l - start + 1);
	if (!res)
		return (NULL);
	while (start < l)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
