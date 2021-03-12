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

void				check_arg(char **av);

#endif
