#include "../include/pile.h"

int		check_isnum(char *arg)
{
	int		i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i])))
			return (-1);
		i++;
	}
	return (0);
}

int		isinteger(char *arg)
{
	long	res;

	res = ft_atoi(arg);
	printf("%ld\n", res);
	if (res > 2147483647 || res < -2147483648)
		return (-1);
	return (0);
}

int		check_double(char **av, int i)
{
	int		j;

	j = i + 1;
	while (av[j])
	{
		if (!(ft_strcmp(av[i], av[j])))
			return (-1);
		j++;
	}
	return (0);
}

void	check_arg(char **av)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (check_isnum(av[i]) == -1
			|| isinteger(av[i]) == -1
			|| check_double(av, i) == -1)
		{
			printf("Error\n");
			exit (1);
		}
		i++;
	}
	return ;
}
