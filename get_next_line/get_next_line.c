// 함수 호출 시 read로 BUFFER_SIZE만큼 파일을 읽어서
//buf에 담게 되면, 중간에 '\n'을 만나거나 파일이 끝나면
//그 포인트를 s_buf에 담아주고 그 s_buf부터 또 읽기 시작
#include "get_next_line.h"

char    *ft_get_buf(int fd,char *s_buf,char *buf)
{
    //버퍼만큼 읽고 담는다.c
    char    *get_buf;//get_buf:문자열을 담는다.
    int     size;
    char    *tmp;
    size = 1;
    while (size)
    {
        size = read(fd, buf, BUFFER_SIZE);// read(fd, 담을 buf, 얼마나 담을것인지)
        // printf("%s", buf);
        if (size <= 0)
            break;
        buf[size] = '\0';
        if (!s_buf)
		{
		    s_buf = malloc(1);
		    s_buf[0] = '\0';
		}
        tmp = s_buf;
        s_buf = ft_strjoin(tmp, buf);
        // printf("%s",s_buf);
        if (ft_strchr(s_buf, '\n') != NULL)
            break ;
        free(tmp);
    }
    return (s_buf);
}

char  *ft_buf_cut(char  *str)
{
    char    *temp;
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            break ;
        i++;
    }
    temp = (char *)malloc(ft_strlen(str) - i);
    if (!temp)
        return NULL;
    int k = i;
    while (str[i])
        temp[j++] = str[i++];
    // temp = ft_substr(str, i, ft_strlen(str)-i);
    str[k] = '\0';
    // printf("%d\n", k);
    temp[j] = '\0';
    // printf("%d\n", j);
    return (temp);
}


char *get_next_line(int fd)
{
    int i;
    static char    *s_buf;
    char    *buf;
    char    *tmp;

    if (BUFFER_SIZE < 0 || fd < 0)
        return NULL;
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    tmp = ft_get_buf(fd, s_buf, buf);
    s_buf = ft_buf_cut(tmp);
    return (tmp);
}

int main()
{
  int fd;

  fd = 1;
  fd = open("./text", O_RDONLY);
  char *line = get_next_line(fd);
  printf("%s", line);
  free(line);
//     line = get_next_line(fd);
//   printf("%s", line);
//   free(line);
  close(fd);
}