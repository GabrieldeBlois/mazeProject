/*
** main.c for t in /home/gaby/rendu/Dantestar/generation/testparfait/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Thu Apr 28 17:37:57 2016 Gabriel de Blois
** Last update Tue May 24 09:22:42 2016 Gabriel de Blois
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include "generation.h"

static	t_algo	algo_tab[] =
{
  &algo_normal,
  &algo_jungled,
  &algo_reverse
};

t_path	*newpath(t_path *next, int x, int y)
{
  t_path	*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (NULL);
  tmp->next = next;
  tmp->x = x;
  tmp->y = y;
  return (tmp);
}

void	begin_algo_main(char **labi, int x, int y)
{
  t_path	*begin;
  int	random;

  if ((begin = newpath(NULL, x, y)) == NULL)
    return ;
  while (begin != NULL)
    {
      labi[begin->y][begin->x] = VISITED;
      random = rand() % 3;
      begin = algo_tab[random](labi, begin);
    }
}

void	make_labi_parfait(void)
{
  char	**labi;
  int	x;
  int	y;

  x = 0;
  y = 0;
  if ((labi = init_labi()) == NULL)
    return ;
  begin_algo_main(labi, x, y);
  test_labi(labi);
  disp_labi(labi);
  free_labi(labi);
}

int	main(int ac, char **av)
{
  srand(time(NULL));
  if (ac < 3)
    return (printf("usage: [width] [height] [parfait]\n"), 0);
  g_width = atoi(av[1]);
  g_height = atoi(av[2]);
  if (g_width <= 0 || g_height <= 0)
    return (0);
  if (ac == 4)
    {
      if (my_strcmp(av[3], "parfait") == 0)
	make_labi_parfait();
      else
	make_labi_imparfait();
    }
  else
    make_labi_imparfait();
  return (0);
}
