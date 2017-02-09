/*
** main.c for dante in /home/flipper/rendu/Dante/DFS/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Thu Apr 28 17:19:05 2016 Matthis Le Texier
** Last update Thu Apr 28 19:01:00 2016 Matthis Le Texier
*/

# define CURRENT 'o'
# define VISITED 'V'
# define UNVISITED '*'

int	my_strlen(char *str);

int	depth_first_search(char *maze, int width, char *stack, int pos)
{
  if (pos == my_strlen(maze) - 1 - width - 1)
    return 1;
  stack[pos] = CURRENT;
  if (pos - 1 > 0 && stack[pos - 1] == UNVISITED)
    if (depth_first_search(maze, width, stack, pos - 1))
      return 1;
  if (pos + 1 < my_strlen(maze) - 1 && stack[pos + 1] == UNVISITED)
    if (depth_first_search(maze, width, stack, pos + 1))
     return 1;
  if (pos - width > 0 && stack[pos - width] == UNVISITED)
    if (depth_first_search(maze, width, stack, pos - width))
      return 1;
  if (pos + width < my_strlen(maze) && stack[pos + width] == UNVISITED)
    if (depth_first_search(maze, width, stack, pos + width))
      return 1;
  stack[pos] = VISITED;
  return 0;
}
