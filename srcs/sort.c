#include "../include/pile.h"

int		find_biggest_nb(t_pile *pile)
{
	t_element	*current;
	int			i;
	int			pos;
	int			nb;

	current = pile->first;
	nb = current->nb;
	i = 0;
	pos = 0;
	while ((current = current->next) != NULL)
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

int		find_smallest_nb(t_pile *pile)
{
	t_element	*current;
	int			i;
	int			pos;
	int			nb;

	current = pile->first;
	nb = current->nb;
	i = 0;
	pos = 0;
	while ((current = current->next) != NULL)
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

int		find_place(t_pile *a, t_pile *b)
{
	t_element	*current;
	int			i;
	int			pos;
	int			nb;
	int			previous_nb;

	current = a->first;
	nb = b->first->nb;
	i = 0;
	pos = pile_length(a);
	previous_nb = 0;
	while (current)
	{
		if (nb > previous_nb && nb < current->nb)
			pos = i;
		i++;
		previous_nb = current->nb;
		current = current->next;
	}
	return (pos);
}

void	sort_3(t_pile *a, t_pile *b)
{
	int		pos;

	pos = find_biggest_nb(a);
	if (pos == 0)
		sort_exec("ra", a, b);
	else if (pos == 1)
		sort_exec("rra", a, b);
	if (a->first->nb > a->first->next->nb)
		sort_exec("sa", a, b);
}

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

void	sort_5(t_pile *a, t_pile *b)
{
	int		i;
	int		pos;
	int		len;

	i = 0;
	len = pile_length(a);
	while (i < len - 3)
	{
		pos = find_smallest_nb(a);
		rotate_n_times(a, b, pos);
		sort_exec("pb", a, b);
		i++;
	}
	sort_3(a, b);
	while (i > 0)
	{
		sort_exec("pa", a, b);
		i--;
	}
}

// void	sort_all(t_pile *a, t_pile *b)
// {
// 	while ()
// }

void	sort_pile(t_pile *a, t_pile *b)
{
	int		len;

	len = pile_length(a);
	if (sorted_check_ps(a, b))
		return ;
	if (len == 2)
		sort_exec("sa", a, b);
	else if (len == 3)
		sort_3(a, b);
	else if (len > 3 && len <= 5)
		sort_5(a, b);
	// else if (len > 5)
	// 	sort_all(a, b);
}
