/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:57:38 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/05/01 12:35:40 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize )
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	if (!src || !dest)
		return ('\0');
	while (i + 1 < dstsize && i < len)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	dest[i] = '\0';
	return (len);
}
