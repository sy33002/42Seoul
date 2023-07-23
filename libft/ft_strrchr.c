/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:40:02 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/05/05 16:22:34 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	cc;
	int		i;

	i = ft_strlen(s);
	cc = (char)c;
	tmp = (char *)s;
	while (i >= 0)
	{
		if ((*(tmp + i)) == cc)
			return (tmp + i);
		i--;
	}
	return (NULL);
}
