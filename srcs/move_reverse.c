/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:29:33 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/15 17:29:34 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

t_move	*best_move_a_to_b_r(t_pile *a, t_pile *b)
{
	t_move		*move;
	t_move		*best_move;
	t_element	*current;
	int			pos;

	pos = 0;
	current = a->first;
	move = init_move();
	best_move = init_move();
	move_in_a_r(best_move, pos, a);
	move_in_b_r(best_move, current->nb, b);
	set_move_in_both(best_move);
	while (current)
	{
		move_in_a_r(move, pos, a);
		move_in_b_r(move, current->nb, b);
		set_move_in_both(move);
		if (best_move->total_move > move->total_move)
			copy_move_to_best_move(move, best_move);
		pos++;
		current = current->next;
	}
	free_move(move);
	return (best_move);
}
