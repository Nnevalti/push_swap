/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:27:40 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/15 17:27:42 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int		check_isnum(char *arg)
{
	int		i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i])))
			return (-1);
		i++;
	}
	return (0);
}

int		isinteger(char *arg)
{
	long	res;

	res = ft_atoi(arg);
	if (res > 2147483647 || res < -2147483648)
		return (-1);
	return (0);
}

int		check_double(char **tab, int i)
{
	int		j;

	j = i + 1;
	while (tab[j])
	{
		if (!(ft_strcmp(tab[i], tab[j])))
			return (-1);
		j++;
	}
	return (0);
}

void	check_arg(char **tab, t_flags *flags)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (check_isnum(tab[i]) == -1
			|| isinteger(tab[i]) == -1
			|| check_double(tab, i) == -1)
		{
			free_tab(tab);
			free(flags);
			printf("Error\n");
			exit(1);
		}
		i++;
	}
	return ;
}
