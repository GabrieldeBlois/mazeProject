/*
** generation.h for t in /home/gaby/rendu/Dantestar/generation/testparfait/include/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Thu Apr 28 17:43:15 2016 Gabriel de Blois
** Last update Fri May 13 16:28:16 2016 Gabriel de Blois
*/

#ifndef	GENERATION_H_
# define GENERATION_H_

# define	WALL	('X')
# define	VISITED ('*')

int	g_width;
int	g_height;

typedef	struct	s_path
{
  int	x;
  int	y;
  struct	s_path	*next;
}	t_path;

typedef t_path	*(*t_algo)(char **labi, t_path *list);

t_path	*newpath(t_path *next, int x, int y);
t_path	*depop_stack(t_path *list);
t_path	*algo_jungled(char **labi, t_path *list);
t_path	*algo_reverse(char **labi, t_path *list);
t_path	*algo_normal(char **labi, t_path *list);
char	**init_labi(void);
t_path	*depop_stack(t_path *list);
void	disp_labi(char **labi);
void	free_labi(char **labi);
int	my_strcmp(const char *s1, const char *s2);
void	make_labi_imparfait(void);
void	test_labi(char **labi);

# endif /* GENERATION_H_ */
