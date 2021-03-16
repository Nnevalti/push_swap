/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:29:24 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/15 17:29:26 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	free_pile(t_pile *stack)
{
	t_element	*current;
	t_element	*element;

	current = stack->first;
	while (current)
	{
		element = current;
		current = current->next;
		free(element);
	}
	free(current);
	free(stack);
	return ;
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

void	free_move(t_move *sort)
{
	free(sort);
	sort = NULL;
	return ;
}
