/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:19:05 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/16 17:19:07 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	final_rotate_r(t_pile *a, t_pile *b)
{
	int		pos;
	int		move;

	pos = find_biggest_nb_pos(a);
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

void	push_back_in_a_r(t_pile *a, t_pile *b)
{
	int		pos;
	int		move;

	while (pile_length(b) > 0)
	{
		pos = find_place_in_pile_descending(b->first->nb, a);
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
	final_rotate_r(a, b);
	return ;
}
