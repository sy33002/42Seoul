/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:57:19 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/08/03 15:09:17 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free2(char *str)
{
	free(str);
	str = NULL;
	return (str);
}

char	*put_null(char *str)
{
	if (!str)
	{
		str = (char *)malloc(sizeof(char) * 1);
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
		free2(tmp);
		if (ft_strchr(s_buf, '\n') != NULL)
			break ;
		if (!s_buf)
			return (NULL);
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
		return (NULL);
	temp = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (!temp)
		return (NULL);
	if (temp[0] == '\0' || !temp)
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
	if (read(fd, NULL, 0) < 0)
	{
		if (!s_buf)
		free (s_buf);
	}
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

// #include <fcntl.h>
// #include <stdio.h>

// int main(void)
// {
//   int fd;

//   fd = 1;
//   fd = open("./read_error.txt", O_RDONLY);
//   char *line = get_next_line(fd);
//   printf("%p\n", line);
//   printf("%s", get_next_line(fd));
//   free(line);
//   //line = get_next_line(fd);
//   //printf("%s", line);
//   //free(line);
//   //line = get_next_line(fd);
//   //printf("%s", line);
//   //free(line);
//   return (0);
// }
