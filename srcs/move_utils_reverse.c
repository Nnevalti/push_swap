/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:36:26 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/15 17:36:27 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	move_in_a_r(t_move *move, int pos, t_pile *a)
{
	int		len;

	len = pile_length(a);
	if (pos >= len / 2)
	{
		move->move_in_a = len - pos;
		move->rotate_r_in_a = TRUE;
	}
	else
	{
		move->move_in_a = pos;
		move->rotate_r_in_a = FALSE;
	}
	return ;
}

void	move_in_b_r(t_move *move, int nb, t_pile *b)
{
	int		len;
	int		pos;

	len = pile_length(b);
	pos = find_place_in_pile_ascending(nb, b);
	if (pos >= len / 2)
	{
		move->move_in_b = len - pos;
		move->rotate_r_in_b = TRUE;
	}
	else
	{
		move->move_in_b = pos;
		move->rotate_r_in_b = FALSE;
	}
	return ;
}
