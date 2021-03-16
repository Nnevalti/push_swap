/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:29:58 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/15 17:29:59 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

t_pile		*init_pile(void)
{
	t_pile	*stack;

	if (!(stack = malloc(sizeof(t_pile))))
		return (NULL);
	stack->first = NULL;
	return (stack);
}

void		empiler(t_pile *stack, int nb)
{
	t_element		*new;

	if (!(new = malloc(sizeof(t_element))) || stack == NULL)
		exit(1);
	new->nb = nb;
	new->next = stack->first;
	stack->first = new;
	return ;
}

int			depiler(t_pile *stack)
{
	int			depile_nb;
	t_element	*depile_element;

	if (stack == NULL)
		exit(1);
	depile_nb = 0;
	depile_element = stack->first;
	if (depile_element != NULL)
	{
		depile_nb = depile_element->nb;
		stack->first = depile_element->next;
		free(depile_element);
	}
	return (depile_nb);
}

int			pile_length(t_pile *stack)
{
	t_element	*current;
	int			i;

	i = 0;
	if (stack->first == NULL)
		return (0);
	current = stack->first;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void		display_pile(t_pile *stack)
{
	t_element *current;

	current = stack->first;
	while (current)
	{
		printf("%d ", current->nb);
		current = current->next;
	}
	printf("\n");
	return ;
}
