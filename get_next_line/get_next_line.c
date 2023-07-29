// 함수 호출 시 read로 BUFFER_SIZE만큼 파일을 읽어서
//buf에 담게 되면, 중간에 '\n'을 만나거나 파일이 끝나면
//그 포인트를 s_buf에 담아주고 그 s_buf부터 또 읽기 시작
#include "get_next_line.h"

char    *ft_get_buf(int fd,char *s_buf,char *buf)
{
    //버퍼만큼 읽고 담는다.c
    char    *get_buf;//get_buf:문자열을 담는다.
    int     size;

    size = 1;
    while (size)
    {
        printf("%s\n", "aaaa");
        size = read(fd, buf, BUFFER_SIZE);// read(fd, 담을 buf, 얼마나 담을것인지)
        printf("%s", buf);
        // if (size <= 0)
        //     break;
    }
    return (buf);
}
    
    
    //tmp_buf = s_buf
    //s_buf = tmp_buf + buf;
    //개행을 찾아 ft_strchr으로 찾았다면 break시켜야대
    //tmp_buf 댕글링 포인터 해제


char *get_next_line(int fd)
{
    int i;
    static char    *s_buf;
    char    *buf;
    char    *tmp;

    // if (BUFFER_SIZE < 0 || fd < 0)
    //     return NULL;
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    printf("%s", "her");
    tmp = ft_get_buf(fd, s_buf, buf);
    return (tmp);
}

int main()
{
  int fd;

  fd = 1;
  fd = open("./test", O_RDONLY);
  printf("%d",fd);
  char *line = get_next_line(fd);
//   printf("%p\n", line);
//   printf("%s", get_next_line(fd));
  free(line);
  close(fd);
}