/*
** parfait.c for t in /home/gaby/rendu/Dantestar/generateur/src/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Wed May 11 22:20:06 2016 Gabriel de Blois
** Last update Wed May 11 22:23:16 2016 Gabriel de Blois
*/

#include <stdlib.h>
#include <unistd.h>
#include "generation.h"

void	make_labi_imparfait(void)
{
  char	buf[g_width];
  char	retour;
  int	i;
  int	j;
  int	error;

  (void)error;
  retour = '\n';
  i = -1;
  while (++i < g_height)
    {
      j = -1;
      while (++j < g_width)
	  buf[j] = (rand() % 4 == 0 && j != 0 && i != g_height - 1) ? WALL : VISITED;
      error = write(1, buf, g_width);
      if (i != g_height - 1)
	error = write(1, &retour, 1);
    }
}
