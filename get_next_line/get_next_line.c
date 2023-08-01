/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:57:19 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/08/01 21:04:14 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free2(char *str)
{
	free(str);
	str = NULL;
}

char	*put_null(char *str)
{
	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	return (str);
}

static char	*ft_get_buf(int size, int fd, char *s_buf, char *buf)
{
	char	*tmp;

	while (size != 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
		{
			free2(s_buf);
			return (NULL);
		}
		if (size == 0)
			break ;
		buf[size] = '\0';
		s_buf = put_null(s_buf);
		tmp = s_buf;
		s_buf = ft_strjoin(tmp, buf);
		if (!s_buf)
			return (NULL);
		free2(tmp);
		if (ft_strchr(s_buf, '\n'))
			break ;
	}
	return (s_buf);
}

static char	*ft_buf_complete(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	while (!(str[i] == '\0' || str[i] == '\n'))
		i++;
	if (str[i] == '\0')
		return (0);
	temp = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (!temp)
		return (NULL);
	if (temp[0] == '\0')
	{
		free2(temp);
		return (NULL);
	}
	str[i + 1] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*s_buf;
	char			*str;
	int				i;

	i = 1;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	str = ft_get_buf(i, fd, s_buf, buf);
	free2(buf);
	if (!str)
		return (NULL);
	s_buf = ft_buf_complete(str);
	return (str);
}
