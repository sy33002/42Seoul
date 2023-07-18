/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:37:25 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/05/01 15:43:35 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		i;
	int		l;

	tmp = NULL;
	i = 0;
	l = ft_strlen(s1) + 1;
	tmp = (char *)ft_calloc(l, 1);
	if (!tmp)
		return (NULL);
	l--;
	while (i < l)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
