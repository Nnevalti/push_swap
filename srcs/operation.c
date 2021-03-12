#include "../include/pile.h"

void	swap_nb(t_pile *pile)
{
	int		tmp[2];

	if (pile_length(pile) < 2)
		return ;
	tmp[0] = depiler(pile);
	tmp[1] = depiler(pile);
	empiler(pile, tmp[0]);
	empiler(pile, tmp[1]);
}

void	push_nb(t_pile *from, t_pile *to)
{
	int		nb;

	if (pile_length(from) < 1)
		return ;
	nb = depiler(from);
	empiler(to, nb);
	return ;
}

void	rotate_nb(t_pile *pile, int len)
{
	int		tmp[len];
	int		i;

	if (len < 2)
		return ;
	i = 0;
	while (i < len)
	{
		tmp[i] = depiler(pile);
		i++;
	}
	empiler(pile, tmp[0]);
	i--;
	while (i > 0)
	{
		empiler(pile, tmp[i]);
		i--;
	}
	return ;
}

void	reverse_rotate_nb(t_pile *pile, int len)
{
	int		tmp[len];
	int		i;

	if (len < 2)
		return ;
	i = 0;
	while (i < len)
	{
		tmp[i] = depiler(pile);
		i++;
	}
	i -= 2;
	while (i >= 0)
	{
		empiler(pile, tmp[i]);
		i--;
	}
	empiler(pile, tmp[len - 1]);
	return ;
}
