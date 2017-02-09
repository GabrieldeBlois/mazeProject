/*home/gaby/rendu/Dantestar/generation/testparfait/include/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Fri Apr 29 15:48:11 2016 Gabriel de Blois
** Last update Fri Apr 29 15:51:13 2016 Gabriel de Blois
*/

#include "generation.h"
#include <stdlib.h>
#include <unistd.h>

int my_putchar(const char c) { return (write(1, &c, 1)); }

void disp_labi(char **labi) {
  int i;

  i = -1;
  while (++i < g_height) {
    if (write(1, labi[i], g_width) < 0)
      exit(1);
    if (i < g_height - 1)
      my_putchar('\n');
  }
}

void free_labi(char **labi) {
  int i;

  i = -1;
  while (++i < g_height)
    free(labi[i]);
  free(labi);
}
