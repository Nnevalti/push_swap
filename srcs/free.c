#include "../include/pile.h"

void	free_pile(t_pile *pile)
{
	t_element	*current;
	t_element	*element;
	current = pile->first;
	while (current)
	{
		element = current;
		current = current->next;
		free(element);
	}
	free(current);
	free(pile);
	return ;
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}
