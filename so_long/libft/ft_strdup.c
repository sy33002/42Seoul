/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:37:25 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/11/26 15:57:52 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*cpy;
	int			i;
	int			len;

	cpy = NULL;
	i = 0;
	len = ft_strlen(s1);
	if (s1[len - 1] == '\n')
		len -= 1;
	cpy = (char *)ft_calloc(len + 1, sizeof(char));
	if (!cpy)
		return (NULL);
	while (i < len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
