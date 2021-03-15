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

#include "../include/pile.h"

int		main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;
	char	**tab;
	int		i;

	if (ac <= 1)
		exit(1);
	tab = parse_arg(av);
	check_arg(tab);
	a = init_pile();
	b = init_pile();
	i = ft_tablen(tab);
	while (i-- > 0)
		empiler(a, ft_atoi(tab[i]));
	free_tab(tab);
	sort_pile(a, b);
	free_pile(a);
	free_pile(b);
	return (0);
}
