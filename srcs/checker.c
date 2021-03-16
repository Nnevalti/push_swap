/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:27:55 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/15 17:27:58 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

char	**ft_append_tab(char **cmds_array, char *cmd)
{
	char	**new_array;
	int		len;
	int		i;

	len = ft_tablen(cmds_array) + 1;
	if (!(new_array = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = 0;
	while (cmds_array != NULL && cmds_array[i])
	{
		new_array[i] = ft_strdup(cmds_array[i]);
		i++;
	}
	new_array[i] = ft_strdup(cmd);
	i++;
	new_array[i] = NULL;
	if (cmds_array != NULL)
		free_tab(cmds_array);
	return (new_array);
}

void	free_flags_and_piles(t_pile *a, t_pile *b, t_flags *flags)
{
	free_pile(a);
	free_pile(b);
	free(flags);
}

void	analyze_cmds(char **cmds_array, t_pile *a, t_pile *b, t_flags *flags)
{
	int		i;
	int		move;

	i = 0;
	move = 0;
	while (cmds_array[i])
	{
		if (exec_cmd(cmds_array[i], a, b) == -1)
		{
			free_tab(cmds_array);
			free_flags_and_piles(a, b, flags);
			printf("Error\n");
			exit(1);
		}
		if (flags->visual == TRUE)
		{
			move++;
			visual(a, b, cmds_array[i], move);
		}
		i++;
	}
	free_tab(cmds_array);
	if (flags->visual == TRUE)
		pile_sorted_visual(a, b, move, flags->reverse);
}

void	read_cmd(t_pile *a, t_pile *b, t_flags *flags)
{
	char	*cmd;
	char	**cmds_array;

	cmds_array = NULL;
	while (42)
	{
		if (get_next_line(0, &cmd) == 0)
		{
			free(cmd);
			break ;
		}
		cmds_array = ft_append_tab(cmds_array, cmd);
		free(cmd);
		cmd = NULL;
	}
	if (cmds_array != NULL)
		analyze_cmds(cmds_array, a, b, flags);
	if (flags->reverse == TRUE)
		sorted_check_r(a, b);
	else
		sorted_check(a, b);
	free_pile(a);
	free_pile(b);
}

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
	read_cmd(a, b, flags);
	free(flags);
	return (0);
}
