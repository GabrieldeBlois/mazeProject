/*
** my.h for t in /home/gaby/rendu/Dantestar/largeur/include/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Wed May 11 14:37:08 2016 Gabriel de Blois
** Last update Wed May 11 22:34:17 2016 Gabriel de Blois
*/

#ifndef		MY_H_
# define	MY_H_

# define	PATH	('*')
# define	VISITED	('o')
# define	WALL	('X')

typedef	struct	s_stack
{
  struct s_stack	*next;
  int	pos;
}	t_stack;

int	g_len;
int	g_width;
int	g_height;

int	get_map_width(const char *str);
char	*get_the_map(const char *filename);
void	free_the_map(char *map);
t_stack *add_paths(char *map, int place, t_stack *last);

#endif

/*
** MY_H_
*/
