#ifndef PILE_H
# define PILE_H
# include <stdio.h>
# include <stdlib.h>
# include "../libft/include/libft.h"

typedef struct		s_element
{
	int				nb;
	struct s_element		*next;
}					t_element;

typedef struct		s_pile
{
	t_element		*first;
}					t_pile;

/*
** CHECK_ARG.C
*/
void				check_arg(char **av);

/*
** PARSING.C
*/
char				**parse_arg(char **av);

/*
**	PILE.C
*/
t_pile				*init_pile();
void				empiler(t_pile *pile, int nb);
int					depiler(t_pile *pile);
int					pile_length(t_pile *pile);
void				display_pile(t_pile *pile);

/*
** FREE.C
*/
void				free_pile(t_pile *pile);
void				free_tab(char **tab);


#endif
