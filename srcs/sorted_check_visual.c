/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_check_visual.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:07:01 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/16 21:07:02 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int		check_sort_visual(t_pile *a, int nb_line, t_bool reverse)
{
	t_element	*current;
	int			previous_nb;
	int			stack_len;

	current = a->first;
	previous_nb = 0;
	stack_len = pile_length(a);
	while (stack_len != nb_line)
	{
		previous_nb = current->nb;
		current = current->next;
		stack_len--;
	}
	if (stack_len == pile_length(a))
		return (1);
	else if (previous_nb < current->nb && reverse == FALSE)
		return (1);
	else if (previous_nb > current->nb && reverse == TRUE)
		return (1);
	return (0);
}

void	print_stack_sorted(t_pile *a, t_pile *b, t_bool reverse)
{
	int		nb_max;
	int		nb_line;

	nb_line = pile_length(a) + pile_length(b);
	nb_max = nb_line;
	while (nb_line > 0)
	{
		if (nb_line <= pile_length(a))
		{
			if (check_sort_visual(a, nb_line, reverse))
				print_stack(a, nb_line, nb_max, GREEN);
			else
				print_stack(a, nb_line, nb_max, RED);
		}
		else
			printf("%25s", "");
		if (nb_line <= pile_length(b))
			print_stack(b, nb_line, nb_max, RED);
		else
			printf("%25s", "");
		printf("\n");
		nb_line--;
		system("sleep 0.05");
	}
}

void	pile_sorted_visual(t_pile *a, t_pile *b, int move, t_bool reverse)
{
	system("clear");
	print_stack_sorted(a, b, reverse);
	printf("%s = %-15d", "STACK A", pile_length(a));
	printf("%s = %-15d\n", "STACK B", pile_length(b));
	printf("MOVE : %d\n", move);
}
