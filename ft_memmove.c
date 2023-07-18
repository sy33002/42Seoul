/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:47:52 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/05/01 12:13:11 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp;
	unsigned char		*str;
	size_t				i;

	tmp = (unsigned char *)dst;
	str = (unsigned char *)src;
	i = len;
	if (tmp == NULL && str == NULL)
		return (NULL);
	if (tmp <= str)
	{
		while (0 < len--)
			*tmp++ = *str++;
	}
	else
	{
		while (0 < i--)
			tmp[i] = str[i];
	}
	return (dst);
}
