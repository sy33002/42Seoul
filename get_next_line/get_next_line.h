/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:57:41 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/08/01 19:00:51 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

// #define BUFFER_SIZE 4

char			*ft_get_buf(int size, int fd, char *s_buf, char *buf);
char			*get_next_line(int fd);
char			*ft_buf_complete(char *str);
char			*get_next_line(int fd);
int				ft_strlen(char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(char *s, int c);
char        	*ft_substr(char *s, int start, int len);


#endif
