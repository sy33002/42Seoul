/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:59:42 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/05/07 17:47:26 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	l;
	size_t	i;
	char	*res;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
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
