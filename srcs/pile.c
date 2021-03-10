#include "../include/pile.h"

t_pile		*init_pile()
{
	t_pile	*pile;

	if (!(pile = malloc(sizeof(t_pile))))
	{
		printf("Malloc failed\n");
		exit (-1);
	}
	pile->first = NULL;
	return (pile);
}

void		empiler(t_pile *pile, int nb)
{
	t_element		*new;

	if (!(new = malloc(sizeof(t_element))) || pile == NULL)
		exit (1);
	new->nb = nb;
	new->next = pile->first;
	pile->first = new;
	return ;
}

int			depiler(t_pile *pile)
{
	int			depile_nb;
	t_element	*depile_element;

	if (pile == NULL)
		exit (1);
	depile_nb = 0;
	depile_element = pile->first;
	if (depile_element != NULL)
	{
		depile_nb = depile_element->nb;
		pile->first = depile_element->next;
		free(depile_element);
	}
	return (depile_nb);
}

int			pile_length(t_pile *pile)
{
	t_element	*current;
	int			i;

	i = 0;
	if (pile == NULL)
		return (0);
	current = pile->first;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}
