/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:30:09 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/15 17:30:10 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int		main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;
	t_flags	*flags;
	char	**tab;
	int		i;

	if (ac <= 1)
		exit(1);
	flags = init_flags();
	tab = parse_arg(av, ac, flags);
	check_arg(tab, flags);
	a = init_pile();
	b = init_pile();
	i = ft_tablen(tab);
	while (i-- > 0)
		empiler(a, ft_atoi(tab[i]));
	free_tab(tab);
	if (flags->reverse == TRUE)
		sort_pile_reverse(a, b);
	else
		sort_pile(a, b);
	free(flags);
	free_pile(a);
	free_pile(b);
	return (0);
}
