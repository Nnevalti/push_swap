/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:04:18 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/16 01:04:19 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pile.h"

void	print_nb_visual(t_element *a, t_element *b)
{
	if (a == NULL && b == NULL)
		printf("%10s \t %10s", "", "");
	else if (a == NULL)
		printf("%10s \t %5s%-5d", "", "", b->nb);
	else if (b == NULL)
		printf("%5s%-5d \t %10s", "", a->nb, "");
	else
		printf("%5s%-5d \t %5s%-5d", "", a->nb, "", b->nb);
	printf("\n");
}

void	display_visual(t_pile *a, t_pile *b, t_flags *flags)
{
	int			len_a;
	int			len_b;
	int			max;
	t_element	*current_a;
	t_element	*current_b;

	(void)flags;
	if (pile_length(a) == 0)
		max = find_max_nb(b);
	else if (pile_length(b) == 0)
		max = find_max_nb(a);
	else
		max = find_max_nb(a) > find_max_nb(b) ? find_max_nb(a) : find_max_nb(b);
	len_a = pile_length(a);
	len_b = pile_length(b);
	current_a = a->first;
	current_b = b->first;
	system("clear");
	while (max > 0)
	{
		if (len_a < max && len_b < max)
		{
			print_nb_visual(NULL, NULL);
		}
		else if (len_a == len_b)
		{
			print_nb_visual(current_a, current_b);
			current_a = current_a->next;
			current_b = current_b->next;
			len_a--;
			len_b--;
		}
		else if (len_a > len_b)
		{
			print_nb_visual(current_a, NULL);
			current_a = current_a->next;
			len_a--;
		}
		else if (len_b > len_a)
		{
			print_nb_visual(NULL, current_b);
			current_b = current_b->next;
			len_b--;
		}
		max--;
	}
	printf("%-5s = %-5d \t ", "PILE A", pile_length(a));
	printf("%-5s = %-5d\n", "PILE B", pile_length(b));
}

void	visual(t_pile *a, t_pile *b, t_flags *flags, char *cmd)
{
	display_visual(a, b, flags);
	printf("CMD: %s\n", cmd);
}
