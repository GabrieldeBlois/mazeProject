/*
** main.c for dante in /home/flipper/rendu/Dante/Dantestar/solve/DFS/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Thu Apr 28 18:13:16 2016 Matthis Le Texier
** Last update Thu Apr 28 19:01:30 2016 Matthis Le Texier
*/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <inttypes.h>

#define READ_SIZE (8192)

int	depth_first_search(char *maze, int width, char *stack, int pos);


size_t	my_strlen(const char *str)
{
  size_t	i;

  if (str == NULL)
    return (0);
  i = -1;
  while (str[++i]);
  return (i);
}

void	my_memset(char *buf, char c, int len)
{
  int	i;

  i = -1;
  while (++i < len)
    buf[i] = c;
}

void	my_strcpy(char *dest, const char *src)
{
  while (*src)
    {
      *dest++ = *src++;
    }
}

void	my_strcat(char *dest, const char *src)
{
  int	i;
  int	j;

  i = -1;
  j = -1;
  while (dest[++i]);
  while (src[++j])
    {
      dest[i++] = src[j];
    }
  dest[i] = '\0';
}

char	*my_strdup(const char *str)
{
  char	*dest;

  if ((dest = malloc(my_strlen(str) + 3)) == NULL)
    return (NULL);
  my_strcpy(dest, str);
  return (dest);
}

char	*concat_buf(char *src, char *buf)
{
  char	*dest = NULL;

  if (src == NULL)
    return (my_strdup(buf));
  if ((dest = malloc(my_strlen(src) + my_strlen(buf) + 2)) == NULL)
    return (NULL);
  my_strcpy(dest, src);
  my_strcat(dest, buf);
  return (free(src), dest);
}

int	get_width_maze(char *maze)
{
  int	i;

  i = 0;
  while (maze[i] && maze[i] != '\n')
    i++;
  return i;
}

int	main(int ac, char **av)
{
  int	fd;
  char	buf[READ_SIZE];
  char	*tmp;
  char	*stack;

  tmp = NULL;
  my_memset(buf, '\0', READ_SIZE);
  if ((fd = open(av[1], O_RDONLY)) < 0)
    return (printf("error on open\n"), 0);
  while (read(fd, buf, READ_SIZE - 1) > 0)
    {
      tmp = concat_buf(tmp, buf);
      my_memset(buf, '\0', READ_SIZE);
    }
  close(fd);
  stack = my_strdup(tmp);
  if (depth_first_search(tmp, get_width_maze(tmp) + 1, stack, 0) == 1)
    printf("FOUND !\n");
  else
    printf("NO WAY !\n");
  printf("stack:\n%s\n", stack);
   //printf("%s\n", tmp);
  return (0);
}
