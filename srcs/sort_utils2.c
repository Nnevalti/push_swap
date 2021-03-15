/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:34:31 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/15 17:34:33 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pile.h"

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

void	final_rotate(t_pile *a, t_pile *b)
{
	int		pos;
	int		move;

	pos = find_smallest_nb_pos(a);
	if (pos >= pile_length(a) / 2)
		move = pile_length(a) - pos;
	else if (pos < pile_length(a) / 2)
		move = pos;
	while (move > 0)
	{
		if (pos >= pile_length(a) / 2)
			sort_exec("rra", a, b);
		else if (pos < pile_length(a) / 2)
			sort_exec("ra", a, b);
		move--;
	}
	return ;
}

void	push_back_in_a(t_pile *a, t_pile *b)
{
	int		pos;
	int		move;

	while (pile_length(b) > 0)
	{
		pos = find_place_in_pile_ascending(b->first->nb, a);
		if (pos >= pile_length(a) / 2)
			move = pile_length(a) - pos;
		else if (pos < pile_length(a) / 2)
			move = pos;
		while (move > 0)
		{
			if (pos >= pile_length(a) / 2)
				sort_exec("rra", a, b);
			else if (pos < pile_length(a) / 2)
				sort_exec("ra", a, b);
			move--;
		}
		sort_exec("pa", a, b);
	}
	final_rotate(a, b);
	return ;
}
