#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	size;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((unsigned int)s_len <= start)
		return (ft_strdup(""));
	size = (unsigned int)s_len - start;
	if (size > len)
		size = len;
	d = (char *)malloc(sizeof(char) * (size + 1));
	if (!d)
		return (NULL);
	i = 0;
	while (i < size)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	d = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!d)
		return (NULL);
	i = 0;
	while (s1[i] && i < s1_len)
	{
		d[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && j < s2_len)
		d[i++] = s2[j++];
	d[i] = '\0';
	return (d);
}
