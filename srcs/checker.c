#include "../include/pile.h"

int		exec_cmd2(char *cmd, t_pile *a, t_pile *b)
{
	if (!ft_strcmp(cmd, "ra"))
		rotate_nb(a, pile_length(a));
	else if (!ft_strcmp(cmd, "rb"))
		rotate_nb(b, pile_length(b));
	else if (!ft_strcmp(cmd, "rr"))
	{
		rotate_nb(a, pile_length(a));
		rotate_nb(b, pile_length(b));
	}
	else if (!ft_strcmp(cmd, "rra"))
		reverse_rotate_nb(a, pile_length(a));
	else if (!ft_strcmp(cmd, "rrb"))
		reverse_rotate_nb(b, pile_length(b));
	else if (!ft_strcmp(cmd, "rrr"))
	{
		reverse_rotate_nb(a, pile_length(a));
		reverse_rotate_nb(b, pile_length(b));
	}
	else
		return (-1);
	return (1);
}

int		exec_cmd(char *cmd, t_pile *a, t_pile *b)
{
	(void)a;
	(void)b;
	if (!ft_strcmp(cmd, "sa"))
		swap_nb(a);
	else if (!ft_strcmp(cmd, "sb"))
		swap_nb(b);
	else if (!ft_strcmp(cmd, "ss"))
	{
		swap_nb(a);
		swap_nb(b);
	}
	else if (!ft_strcmp(cmd, "pa"))
		push_nb(b, a);
	else if (!ft_strcmp(cmd, "pb"))
		push_nb(a, b);
	else if (exec_cmd2(cmd, a, b) == -1)
		return (-1);
	return (1);
}

void	read_cmd(t_pile *a, t_pile *b)
{
	char	*cmd;

	while (42)
	{
		if (get_next_line(0, &cmd) == 0)
		{
			free(cmd);
			break ;
		}
		if (exec_cmd(cmd, a, b) == -1)
		{
			free(cmd);
			free_pile(a);
			free_pile(b);
			printf("Error\n");
			exit(1);
		}
		free(cmd);
		cmd = NULL;
	}
	display_pile(a);
	display_pile(b);
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
	{
		empiler(a, ft_atoi(tab[i]));
	}
	free_tab(tab);
	read_cmd(a, b);
	return (0);
}
