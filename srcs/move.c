#include "../include/pile.h"

t_move	*init_move(void)
{
	t_move	*move;

	if (!(move = malloc(sizeof(t_move))))
		return (NULL);
	move->rotate_r_in_a = FALSE;
	move->rotate_r_in_b = FALSE;
	move->move_in_a = 0;
	move->move_in_b = 0;
	move->move_in_both = 0;
	return (move);
}


void	move_in_a(t_move *move, int pos, t_pile *a)
{
	int		len;

	len = pile_length(a);
	if (pos >= len / 2)
	{
		move->move_in_a = len - pos;
		move->rotate_r_in_a = TRUE;
	}
	else
	{
		move->move_in_a = pos;
		move->rotate_r_in_a = FALSE;
	}
	return ;
}

void	move_in_b(t_move *move, int nb, t_pile *b)
{
	int		len;
	int		pos;

	len = pile_length(b);
	pos = find_place_in_pile_descending(nb, b);
	if (pos >= len / 2)
	{
		move->move_in_b = len - pos;
		move->rotate_r_in_b = TRUE;
	}
	else
	{
		move->move_in_b = pos;
		move->rotate_r_in_b = FALSE;
	}
	return ;
}

void	move_in_a_and_b(t_move *move, t_pile *a, t_pile *b, int pos, int nb)
{
	move_in_a(move, pos, a);
	move_in_b(move, nb, b);
	if (move->rotate_r_in_a == move->rotate_r_in_b)
	{
		if (move->move_in_a < move->move_in_b)
		{
			move->move_in_both = move->move_in_a;
			move->move_in_b -= move->move_in_a;
			move->move_in_a = 0;
		}
		else if (move->move_in_b < move->move_in_a)
		{
			move->move_in_both = move->move_in_b;
			move->move_in_a -= move->move_in_b;
			move->move_in_b = 0;
		}
		else
		{
			move->move_in_both = move->move_in_a;
			move->move_in_a = 0;
			move->move_in_b = 0;
		}
	}
	else
		move->move_in_both = 0;
	move->total_move = move->move_in_a + move->move_in_b + move->move_in_both;
}

t_move	*best_move_a_to_b(t_pile *a, t_pile *b)
{
	t_move		*move;
	t_move		*best_move;
	t_element	*current;
	int			pos;

	pos = 0;
	current = a->first;
	move = init_move();
	best_move = init_move();
	move_in_a_and_b(best_move, a, b, pos, current->nb);
	while(current)
	{
		move_in_a_and_b(move, a, b, pos, current->nb);
		if (best_move->total_move > move->total_move)
			move_in_a_and_b(best_move, a, b, pos, current->nb);
		pos++;
		current = current->next;
	}
	free_move(move);
	return (best_move);
}
