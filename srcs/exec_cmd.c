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

void	exec_best_move(t_move *best_move, t_pile *a, t_pile *b)
{

	while (best_move->move_in_both > 0)
	{
		if (best_move->rotate_r_in_a == TRUE
				&& best_move->rotate_r_in_b == TRUE)
			sort_exec("rrr", a, b);
		else
			sort_exec("rr", a, b);
		best_move->move_in_both--;
	}
	while (best_move->move_in_a > 0)
	{
		if (best_move->rotate_r_in_a == TRUE)
			sort_exec("rra", a, b);
		else
			sort_exec("ra", a, b);
		best_move->move_in_a--;
	}
	while (best_move->move_in_b > 0)
	{
		if (best_move->rotate_r_in_b == TRUE)
			sort_exec("rrb", a, b);
		else
			sort_exec("rb", a, b);
		best_move->move_in_b--;
	}
	sort_exec("pb", a, b);
}
