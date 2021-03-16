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

#include "../include/stack.h"

int		find_place_in_pile_descending(int nb, t_pile *stack)
{
	t_element	*current;
	int			pos;
	int			previous_nb;

	pos = 0;
	current = stack->first;
	if (nb > find_max_nb(stack))
		return (find_biggest_nb_pos(stack));
	if (nb < find_min_nb(stack))
		return (find_smallest_nb_pos(stack) + 1);
	previous_nb = stack->first->nb;
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

int		find_place_in_pile_ascending(int nb, t_pile *stack)
{
	t_element	*current;
	int			pos;
	int			previous_nb;

	pos = 0;
	current = stack->first;
	if (nb > find_max_nb(stack))
		return (find_biggest_nb_pos(stack) + 1);
	if (nb < find_min_nb(stack))
		return (find_smallest_nb_pos(stack));
	previous_nb = stack->first->nb;
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
