/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:14:21 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/05/05 16:28:59 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	f;
	char			*str;

	i = 0;
	f = (unsigned char)c;
	str = (char *)s;
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
