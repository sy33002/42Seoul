#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
#define BUFFER_SIZE 4

int     ft_strlen(char	*str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char    *ft_get_buf(int fd,char *s_buf,char *buf);
char *get_next_line(int fd);
int	ft_len(char *src, unsigned int idx, int len);
char	*ft_substr(char *s, int start, int len);


#endif