/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:29:41 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/15 17:29:42 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	swap_nb(t_pile *stack)
{
	int		tmp[2];

	if (pile_length(stack) < 2)
		return ;
	tmp[0] = depiler(stack);
	tmp[1] = depiler(stack);
	empiler(stack, tmp[0]);
	empiler(stack, tmp[1]);
}

void	push_nb(t_pile *from, t_pile *to)
{
	int		nb;

	if (pile_length(from) < 1)
		return ;
	nb = depiler(from);
	empiler(to, nb);
	return ;
}

void	rotate_nb(t_pile *stack, int len)
{
	int		tmp[len];
	int		i;

	if (len < 2)
		return ;
	i = 0;
	while (i < len)
	{
		tmp[i] = depiler(stack);
		i++;
	}
	empiler(stack, tmp[0]);
	i--;
	while (i > 0)
	{
		empiler(stack, tmp[i]);
		i--;
	}
	return ;
}

void	reverse_rotate_nb(t_pile *stack, int len)
{
	int		tmp[len];
	int		i;

	if (len < 2)
		return ;
	i = 0;
	while (i < len)
	{
		tmp[i] = depiler(stack);
		i++;
	}
	i -= 2;
	while (i >= 0)
	{
		empiler(stack, tmp[i]);
		i--;
	}
	empiler(stack, tmp[len - 1]);
	return ;
}
