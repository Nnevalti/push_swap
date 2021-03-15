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

#include "../include/pile.h"

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

void	analyze_cmds(char **cmds_array, t_pile *a, t_pile *b)
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
			free_pile(a);
			free_pile(b);
			printf("Error\n");
			exit(1);
		}
		move++;
		i++;
	}
	// printf("MOVE : %d\n", move - 100);
	free_tab(cmds_array);
}

void	read_cmd(t_pile *a, t_pile *b)
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
		analyze_cmds(cmds_array, a, b);
	sorted_check(a, b);
	free_pile(a);
	free_pile(b);
}

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
	read_cmd(a, b);
	return (0);
}
