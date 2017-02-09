/*
** main.c for t in /home/gaby/rendu/Dantestar/largeur/src/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Wed May 11 14:38:55 2016 Gabriel de Blois
** Last update Sat May 21 14:58:42 2016 Gabriel de Blois
*/

#include "my.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define DEFAULT "\033[00m"
#define GREEN "\033[0;32m"
#define HIGHLIGHTED "\033[2;102m"
#define DELETION "\033[2;103m"
#define TEAL "\033[1;34m"
#define RED "\033[1;31m"

t_stack *popstack(t_stack *next, int place) {
  t_stack *tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (NULL);
  return (tmp->next = next, tmp->pos = place, tmp);
}

t_stack *algo_engine(t_stack *list, int place, char *map) {
  if (place != g_len - 1) {
    if (map[place + 1] == PATH)
      return (popstack(list, place + 1));
  }
  if (place < g_len - g_width) {
    if (map[place + g_width + 1] == PATH)
      return (popstack(list, place + g_width + 1));
  }
  if (place != 0) {
    if (map[place - 1] == PATH)
      return (popstack(list, place - 1));
  }
  if (place > g_width) {
    if (map[place - (g_width + 1)] == PATH)
      return (popstack(list, place - (g_width + 1)));
  }
  return (list->next);
}

void launch_algo(char *map) {
  t_stack *list;

  if ((list = malloc(sizeof(*list))) == NULL)
    return;
  map[0] = VISITED;
  list->next = NULL;
  list->pos = 0;
  while (list) {
    map[list->pos] = VISITED;
    if (list->pos == g_len - 1)
      break;
    list = algo_engine(list, list->pos, map);
  }
}

int main(int ac, const char **av) {
  char *map;
  int error;

  if (ac != 2)
    return (fprintf(stderr, "Usage: %s [map.txt]\n", av[0]), EXIT_SUCCESS);
  if ((map = get_the_map(av[1])) == NULL)
    return (EXIT_FAILURE);
  (void)error;
  launch_algo(map);
  if (map[g_len - 1] == VISITED && map[0] != WALL)
    error = write(STDOUT_FILENO, map, g_len);
  else
    printf("No solution found\n");
  return (free_the_map(map), EXIT_SUCCESS);
}
