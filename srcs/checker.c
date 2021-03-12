#include "../include/pile.h"

int		main(int ac, char **av)
{
	t_pile	*a;
	// t_pile	*b;
	char	**tab;
	int		i;

	if (ac <= 1)
		exit (1);
	tab = parse_arg(av);
	check_arg(tab);
	a = init_pile();
	// b = init_pile();
	i = ft_tablen(tab);
	while (i-- > 0)
	{
		empiler(a, ft_atoi(tab[i]));
	}
	display_pile(a);
	free_tab(tab);
	free_pile(a);
	return (0);
}
