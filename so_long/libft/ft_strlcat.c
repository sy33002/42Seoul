/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:57:33 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/05/06 21:06:33 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dest, const char *src, size_t dstsize)
{
	size_t	l_dest;
	size_t	l_src;
	size_t	i_src;

	l_dest = ft_strlen(dest);
	l_src = ft_strlen(src);
	i_src = 0;
	if (l_dest + 1 > dstsize)
		return (l_src + dstsize);
	while (src[i_src] != '\0' && l_dest + 1 + i_src < dstsize)
	{
		dest[l_dest + i_src] = src[i_src];
		i_src++;
	}
	dest[l_dest + i_src] = '\0';
	return (l_dest + l_src);
}
