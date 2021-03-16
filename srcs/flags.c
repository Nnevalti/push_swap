/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:46:41 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/16 00:46:42 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

t_flags		*init_flags(void)
{
	t_flags	*flags;

	if (!(flags = malloc(sizeof(t_flags))))
		return (NULL);
	flags->reverse = FALSE;
	flags->visual = FALSE;
	return (flags);
}

int			check_for_flags_checker(char **av, t_flags *flags)
{
	int		i;

	i = 1;
	while (av[i] && i < 4)
	{
		if (!ft_strcmp("-r", av[i]))
			flags->reverse = TRUE;
		else if (!ft_strcmp("-v", av[i]))
			flags->visual = TRUE;
		else
			return (i);
		i++;
	}
	return (i);
}
