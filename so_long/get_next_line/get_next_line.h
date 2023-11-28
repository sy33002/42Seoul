/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:57:41 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/11/28 16:26:22 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 30

char			*get_next_line(int fd);
char			*get_next_line(int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(char *s, int c);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*put_null(char *str);
size_t			ft_strlen(const char *s);

#endif