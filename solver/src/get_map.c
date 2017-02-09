/*
** get_map.c for t in /home/gaby/rendu/Dantestar/largeur/src/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Wed May 11 15:42:01 2016 Gabriel de Blois
** Last update Wed May 11 16:33:38 2016 Gabriel de Blois
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "my.h"

int	get_map_width(const char *str)
{
  int	i;

  i = -1;
  while (str[++i] && str[i] != '\n');
  return (i);
}

char	*get_the_map(const char *filename)
{
  int	fd;
  struct stat	sb;
  char	*map;

  if ((fd = open(filename, O_RDONLY)) < 0)
    return (fprintf(stderr, "error: cannot read %s\n", filename), NULL);
  if (fstat(fd, &sb) < 0)
    return (fprintf(stderr, "error: Cannot stat %s\n", filename), NULL);
  g_len = sb.st_size;
  map = mmap(NULL, g_len, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
  if (map == MAP_FAILED)
    return (perror("mmap"), NULL);
  g_width = get_map_width(map);
  g_height = g_len / g_width;
  close(fd);
  return (map);
}

void	free_the_map(char *map)
{
   if (munmap(map, g_len) == -1)
    {
        perror("unmap");
        exit(EXIT_FAILURE);
    }
}
