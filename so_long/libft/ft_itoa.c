/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:02:05 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/12/02 12:53:42 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	malloclen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len = 1;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_sign(int *n, int *minor)
{
	if (*n < 0)
		*minor = 1;
	else
		*minor = 0;
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		minor;

	i = malloclen(n) - 1;
	ft_sign (&n, &minor);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(i + 2);
	if (!(str))
		return (NULL);
	if (n < 0)
		n = n * -1;
	str[i + 1] = '\0';
	if (minor == 1)
		str[0] = '-';
	while (n > 0)
	{
		str[i] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (str);
}
