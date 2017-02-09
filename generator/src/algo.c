/*
** algo.c for t in /home/gaby/rendu/Dantestar/generation/testparfait/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Fri Apr 29 14:24:36 2016 Gabriel de Blois
** Last update Fri May 13 16:26:56 2016 Gabriel de Blois
*/

#include "generation.h"
#include <stdlib.h>

char **init_labi(void) {
  int i;
  int j;
  char **labi;

  if ((labi = malloc((g_height) * sizeof(char *))) == NULL)
    return (NULL);
  i = -1;
  while (++i < g_height) {
    if ((labi[i] = malloc(g_width)) == NULL)
      return (NULL);
  }
  i = -1;
  while (++i < g_height) {
    j = -1;
    while (++j < g_width)
      labi[i][j] = WALL;
  }
  return (labi);
}

t_path *depop_stack(t_path *list) {
  t_path *tmp;

  if ((tmp = list->next) == NULL)
    return (free(list), NULL);
  return (free(list), tmp);
}

t_path *algo_jungled(char **labi, t_path *list) {
  if (list->y - 2 > 0)
    if (labi[list->y - 2][list->x] == WALL) {
      labi[list->y - 1][list->x] = VISITED;
      return (newpath(list, list->x, list->y - 2));
    }
  if (list->x - 2 > 0)
    if (labi[list->y][list->x - 2] == WALL) {
      labi[list->y][list->x - 1] = VISITED;
      return (newpath(list, list->x - 2, list->y));
    }
  if (list->y + 2 < g_height)
    if (labi[list->y + 2][list->x] == WALL) {
      labi[list->y + 1][list->x] = VISITED;
      return (newpath(list, list->x, list->y + 2));
    }
  if (list->x + 2 < g_width)
    if (labi[list->y][list->x + 2] == WALL) {
      labi[list->y][list->x + 1] = VISITED;
      return (newpath(list, list->x + 2, list->y));
    }
  return (depop_stack(list));
}

t_path *algo_reverse(char **labi, t_path *list) {
  if (list->y + 2 < g_height)
    if (labi[list->y + 2][list->x] == WALL) {
      labi[list->y + 1][list->x] = VISITED;
      return (newpath(list, list->x, list->y + 2));
    }
  if (list->x + 2 < g_width)
    if (labi[list->y][list->x + 2] == WALL) {
      labi[list->y][list->x + 1] = VISITED;
      return (newpath(list, list->x + 2, list->y));
    }
  if (list->y - 2 > 0)
    if (labi[list->y - 2][list->x] == WALL) {
      labi[list->y - 1][list->x] = VISITED;
      return (newpath(list, list->x, list->y - 2));
    }
  if (list->x - 2 > 0)
    if (labi[list->y][list->x - 2] == WALL) {
      labi[list->y][list->x - 1] = VISITED;
      return (newpath(list, list->x - 2, list->y));
    }
  return (depop_stack(list));
}

t_path *algo_normal(char **labi, t_path *list) {
  if (list->x - 2 > 0)
    if (labi[list->y][list->x - 2] == WALL) {
      labi[list->y][list->x - 1] = VISITED;
      return (newpath(list, list->x - 2, list->y));
    }
  if (list->y - 2 > 0)
    if (labi[list->y - 2][list->x] == WALL) {
      labi[list->y - 1][list->x] = VISITED;
      return (newpath(list, list->x, list->y - 2));
    }
  if (list->x + 2 < g_width)
    if (labi[list->y][list->x + 2] == WALL) {
      labi[list->y][list->x + 1] = VISITED;
      return (newpath(list, list->x + 2, list->y));
    }
  if (list->y + 2 < g_height)
    if (labi[list->y + 2][list->x] == WALL) {
      labi[list->y + 1][list->x] = VISITED;
      return (newpath(list, list->x, list->y + 2));
    }
  return (depop_stack(list));
}
