/*
** utils.c for t in /home/gaby/rendu/Dantestar/generateur/testparfait/src/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Wed May 11 13:30:26 2016 Gabriel de Blois
** Last update Fri May 13 16:28:08 2016 Gabriel de Blois
*/

#include "generation.h"

int my_strcmp(const char *s1, const char *s2) {
  while (*s1 && *s2) {
    if (*s1++ != *s2++)
      return (*s1 - *s2);
  }
  return (*s1 - *s2);
}

void test_labi(char **labi) {
  if (g_width > 1 && g_height > 1 && (g_width % 2 == 0 || g_height % 2 == 0)) {
    labi[g_height - 1][g_width - 1] = VISITED;
    labi[g_height - 1][g_width - 2] = VISITED;
  }
}
