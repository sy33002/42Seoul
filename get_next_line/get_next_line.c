/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:57:19 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/08/01 19:00:55 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free2(char *str)
{
	free(str);
	str = NULL;
}

char	*ft_get_buf(int size, int fd, char *s_buf, char *buf)
{
	char	*tmp;
	
	while (size)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == 0)
			break ;
		else if (size == -1)
			return (NULL);
		buf[size] = '\0';
		if (!s_buf)
		{
			s_buf = malloc(1);
			s_buf[0] = '\0';
		}
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

static char	*ft_buf_cut(char *str)
{
	char	*temp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (!(str[i] == '\0' || str[i] == '\n'))
		i++;
	k = i;
	temp = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (!temp)
		return (NULL);
	if (temp[0] == '\0')
	{
		free2(temp);
		return (NULL);
	}
	// temp[i] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*s_buf;
	char		*buf;
	char		*tmp;
	int			size;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	size = 1;
	// printf("%p\n", )
	tmp = ft_get_buf(size, fd, s_buf, buf);
	if (!tmp)
	{
		free2(tmp);
		return (NULL);
	}
	s_buf = ft_buf_cut(tmp);
	free(buf);
	return (tmp);
}

// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//   int fd;

//   fd = 1;
//   fd = open("./text", O_RDONLY);
//   char *line = get_next_line(fd);
//   printf("%s\n", "----answer---");
//   printf("%p\n", line);
//   printf("%s", line);
//   free(line);
//   //line = get_next_line(fd);
//   //printf("%s", line);
//   //free(line);
//   //line = get_next_line(fd);
//   //printf("%s", line);
//   //free(line);
//   return (0);
// }
