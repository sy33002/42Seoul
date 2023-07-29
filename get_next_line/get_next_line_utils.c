#include "get_next_line.h"

int ft_strlen(char *str)
{
	int	i;

	if (!str)
		return 0;
	i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	s1_len;
	int	s2_len;
	char	*tmp;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	tmp = (char *)malloc(s1_len + s2_len + 1);
	if (!tmp)
		return (NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		tmp[s1_len++] = s2[i++];
	tmp[s1_len] = '\0';
	return (tmp);
}

char	*ft_strchr(char *s, int c)
{
	int				i;
	unsigned char	f;
	char			*str;

	i = 0;
	f = (unsigned char)c;
	str = (char *)s;
	while (str[i])
	{
		if (f == str[i])
			return (str + i);
		i++;
	}
	if (f == str[i])
		return (str + i);
	return (NULL);
}

int	ft_len(char *src, unsigned int idx, int len)
{
	int	size;
	int	start;

	start = idx;
	size = ft_strlen(src) - idx + 1;
	if (size < len)
		return (size);
	else
		return (len);
}

char	*ft_substr(char *s, int start, int len)
{
	int	i;
	int	length;
	char	*cpy;

	i = 0;
	if (!s)
		return (NULL);
	if ((int)start >= ft_strlen(s))
	{
		cpy = malloc(1);
		if (!cpy)
			return (NULL);
		cpy[0] = '\0';
		return (cpy);
	}
	length = ft_len(s, start, len);
	cpy = (char *)malloc(sizeof(char) * (length + 1));
	if (!cpy)
		return (NULL);
	while (i < length)
		cpy[i++] = s[start++];
	cpy[i] = '\0';
	return (cpy);
}