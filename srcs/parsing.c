/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:29:50 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/15 17:29:51 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pile.h"

char	**ft_join_tab(char **tab, char **tmp_tab)
{
	char	**new_tab;
	int		len;
	int		i;
	int		j;

	len = ft_tablen(tab) + ft_tablen(tmp_tab);
	if (!(new_tab = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < ft_tablen(tab))
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	j = 0;
	while (j < ft_tablen(tmp_tab))
	{
		new_tab[i + j] = ft_strdup(tmp_tab[j]);
		j++;
	}
	free_tab(tab);
	free_tab(tmp_tab);
	new_tab[i + j] = NULL;
	return (new_tab);
}

char	**parse_arg_push_swap(char **av)
{
	char	**tab;
	char	**tmp_tab;
	int		i;

	i = 1;
	tab = ft_split(av[i], ' ');
	while (av[i] && av[i + 1])
	{
		tmp_tab = ft_split(av[i + 1], ' ');
		tab = ft_join_tab(tab, tmp_tab);
		i++;
	}
	return (tab);
}

char	**parse_arg_checker(char **av, int ac, t_flags *flags)
{
	char	**tab;
	char	**tmp_tab;
	int		i;

	i = check_for_flags_checker(av, flags);
	if (i == ac)
	{
		free(flags);
		printf("Error\n");
		exit(1);
	}
	tab = ft_split(av[i], ' ');
	while (av[i] && av[i + 1])
	{
		tmp_tab = ft_split(av[i + 1], ' ');
		tab = ft_join_tab(tab, tmp_tab);
		i++;
	}
	return (tab);
}
