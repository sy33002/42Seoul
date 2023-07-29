size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
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

char	*ft_strchr(const char *s, int c)
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
