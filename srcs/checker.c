#include "../include/pile.h"

int		main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;

	if (ac <= 1)
		exit (1);
	check_arg(av);
	a = init_pile();
	b = init_pile();
	for (int i = 0; av[i]; i++)
		printf("av[%d] = %s\n", i, av[i]);
	return (0);
}
