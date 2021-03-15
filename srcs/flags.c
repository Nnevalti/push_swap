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

#include "../include/pile.h"

t_flags		*init_flags(void)
{
	t_flags	*flags;

	if (!(flags = malloc(sizeof(t_flags))))
		return (NULL);
	flags->reverse = FALSE;
	flags->visual = FALSE;
	flags->color = FALSE;
	return (flags);
}

int			check_for_flags_checker(char **av, t_flags *flags)
{
	if (av[1] && !ft_strcmp("-v", av[1]))
	{
		flags->visual = TRUE;
		if (av[2] && !ft_strcmp("-c", av[2]))
		{
			flags->color = TRUE;
			return (3);
		}
		return (2);
	}
	return (1);
}
