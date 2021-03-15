#include "../include/pile.h"

void	rotate_n_times(t_pile *a, t_pile *b, int pos)
{
	int		len;

	len = pile_length(a);
	if (pos <= len / 2)
	{
		while (pos != 0)
		{
			sort_exec("ra", a, b);
			pos--;
		}
	}
	else if (pos > len / 2)
	{
		while (pos != len)
		{
			sort_exec("rra", a, b);
			pos++;
		}
	}
	return ;
}

int		find_biggest_nb_pos(t_pile *pile)
{
	t_element	*current;
	int			i;
	int			pos;
	int			nb;

	current = pile->first;
	nb = current->nb;
	i = 0;
	pos = 0;
	while ((current = current->next))
	{
		i++;
		if (current->nb > nb)
		{
			nb = current->nb;
			pos = i;
		}
	}
	return (pos);
}

int		find_smallest_nb_pos(t_pile *pile)
{
	t_element	*current;
	int			i;
	int			pos;
	int			nb;

	current = pile->first;
	nb = current->nb;
	i = 0;
	pos = 0;
	while ((current = current->next))
	{
		i++;
		if (current->nb < nb)
		{
			nb = current->nb;
			pos = i;
		}
	}
	return (pos);
}

int		find_min_nb(t_pile *pile)
{
	t_element	*current;
	int			nb;

	current = pile->first;
	nb = current->nb;
	while (current)
	{
		if (current->nb < nb)
			nb = current->nb;
		current = current->next;
	}
	return (nb);
}

int		find_max_nb(t_pile *pile)
{
	t_element	*current;
	int			nb;

	current = pile->first;
	nb = current->nb;
	while (current)
	{
		if (current->nb > nb)
			nb = current->nb;
		current = current->next;
	}
	return (nb);
}

int		find_place_in_pile_descending(int nb, t_pile *pile)
{
	t_element	*current;
	int			pos;
	int			previous_nb;

	pos = 0;
	current = pile->first;
	if (nb > find_max_nb(pile))
		return (find_biggest_nb_pos(pile));
	if (nb < find_min_nb(pile))
		return (find_smallest_nb_pos(pile) + 1);
	previous_nb = pile->first->nb;
	while (current)
	{
		if (previous_nb > nb && nb > current->nb)
			return (pos);
		previous_nb = current->nb;
		current = current->next;
		pos++;
	}
	return (0);
}

int		find_place_in_pile_ascending(int nb, t_pile *pile)
{
	t_element	*current;
	int			pos;
	int			previous_nb;

	pos = 0;
	current = pile->first;
	if (nb > find_max_nb(pile))
		return (find_biggest_nb_pos(pile) + 1);
	if (nb < find_min_nb(pile))
		return (find_smallest_nb_pos(pile));
	previous_nb = pile->first->nb;
	while (current)
	{
		if (previous_nb < nb && nb < current->nb)
			return (pos);
		previous_nb = current->nb;
		current = current->next;
		pos++;
	}
	return (0);
}
