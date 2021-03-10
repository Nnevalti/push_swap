#include "../include/pile.h"

int		check_isnum(char *nb)
{
	int		i;

	i = 0;
	while (nb[i])
	{
		// if ()
		i++;
		return (0);
	}
	return (1);
}

void	check_arg(char **av)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (check_isnum(av[i]))
		{
			printf("Error\n");
			exit (1);
		}
		i++;
	}
	return ;
}

int		main(int ac, char **av)
{
	// t_pile	*a;
	// t_pile	*b;

	if (ac <= 1)
		exit (0);
	// check_arg(av);
	// a = init_pile();
	// b = init_pile();
	for (int i = 0; av[i]; i++)
		printf("av[%d] = %s\n", i, av[i]);
	return (0);
}
