/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:19:11 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/05/06 16:44:56 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t	n)
{
	unsigned char	*res;
	unsigned char	*arr;
	size_t			i;

	i = 0;
	res = (unsigned char *)dst;
	arr = (unsigned char *)src;
	if (dst == src || n == 0)
		return (res);
	while (i < n)
	{
		res[i] = arr[i];
		i++;
	}
	return (res);
}
