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

void	sort_exec(char *cmd, t_pile *a, t_pile *b)
{
	exec_cmd(cmd, a, b);
	printf("%s\n", cmd);
}
