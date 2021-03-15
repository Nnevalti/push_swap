/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:30:35 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/15 17:30:36 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
