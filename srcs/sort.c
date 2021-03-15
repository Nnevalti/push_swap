#include "../include/pile.h"

void	sort_3(t_pile *a, t_pile *b)
{
	int		pos;

	pos = find_biggest_nb_pos(a);
	if (pos == 0)
		sort_exec("ra", a, b);
	else if (pos == 1)
		sort_exec("rra", a, b);
	if (a->first->nb > a->first->next->nb)
		sort_exec("sa", a, b);
}

void	sort_5(t_pile *a, t_pile *b)
{
	int		i;
	int		pos;
	int		len;

	i = 0;
	len = pile_length(a);
	while (i < len - 3)
	{
		pos = find_smallest_nb_pos(a);
		rotate_n_times(a, b, pos);
		sort_exec("pb", a, b);
		i++;
	}
	sort_3(a, b);
	while (i > 0)
	{
		sort_exec("pa", a, b);
		i--;
	}
}

void	final_rotate(t_pile *a, t_pile *b)
{
	int		pos;
	int		move;

	pos = find_smallest_nb_pos(a);
	if (pos >= pile_length(a) / 2)
		move = pile_length(a) - pos;
	else if (pos < pile_length(a) / 2)
		move = pos;
	while (move > 0)
	{
		if (pos >= pile_length(a) / 2)
			sort_exec("rra", a, b);
		else if (pos < pile_length(a) / 2)
			sort_exec("ra", a, b);
		move--;
	}
	return ;
}

void	push_back_in_a(t_pile *a, t_pile *b)
{
	int		pos;
	int		move;

	while (pile_length(b) > 0)
	{
		pos = find_place_in_pile_ascending(b->first->nb, a);
		if (pos >= pile_length(a) / 2)
			move = pile_length(a) - pos;
		else if (pos < pile_length(a) / 2)
			move = pos;
		while (move > 0)
		{
			if (pos >= pile_length(a) / 2)
				sort_exec("rra", a, b);
			else if (pos < pile_length(a) / 2)
				sort_exec("ra", a, b);
			move--;
		}
		sort_exec("pa", a, b);
	}
	final_rotate(a, b);
	return ;
}


void	optimizer_push(t_pile *a, t_pile *b)
{
	int		pos;

	pos = 0;
	while (pile_length(a) > 2)
	{
		pos = find_smallest_nb_pos(a);
		if (pos == 0)
			sort_exec("pb", a, b);
		else if (pos >= pile_length(a) / 2)
			sort_exec("rra", a, b);
		else if (pos < pile_length(a) / 2)
			sort_exec("ra", a, b);
	}
	return ;
}

void	sort_all(t_pile *a, t_pile *b)
{
	int		optimizer;
	t_move	*best_move;

	optimizer = pile_length(a) > 200 ? 50 : 2;
	// optimizer = 0;
	sort_exec("pb", a, b);
	sort_exec("pb", a, b);
	while (pile_length(a) > optimizer)
	{
		best_move = best_move_a_to_b(a, b);
		exec_best_move(best_move, a, b);
		free_move(best_move);
	}
	optimizer_push(a, b);
	push_back_in_a(a, b);
}

void	sort_pile(t_pile *a, t_pile *b)
{
	int		len;

	len = pile_length(a);
	if (sorted_check_ps(a, b))
		return ;
	if (len == 2)
		sort_exec("sa", a, b);
	else if (len == 3)
		sort_3(a, b);
	else if (len > 3 && len <= 5)
		sort_5(a, b);
	else if (len > 5)
		sort_all(a, b);
	return ;
}
