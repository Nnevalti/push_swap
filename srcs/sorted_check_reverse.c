/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_check_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:35:45 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/16 13:35:46 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int		check_pile_sorted_r(t_pile *stack)
{
	t_element	*current;
	int			previous_nb;

	if (stack == NULL || stack->first == NULL)
		return (0);
	current = stack->first;
	previous_nb = current->nb;
	while (current->next)
	{
		current = current->next;
		if (previous_nb < current->nb)
			return (0);
		previous_nb = current->nb;
	}
	return (1);
}

void	sorted_check_r(t_pile *a, t_pile *b)
{
	if (pile_length(b) == 0)
	{
		if (check_pile_sorted_r(a))
			printf("OK\n");
		else
			printf("KO\n");
	}
	else
		printf("KO\n");
	return ;
}

int		sorted_check_r_ps(t_pile *a, t_pile *b)
{
	if (pile_length(b) == 0)
	{
		if (check_pile_sorted_r(a))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
