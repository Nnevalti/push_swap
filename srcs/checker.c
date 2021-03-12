#include "../include/pile.h"

int		exec_cmd(char *cmd, t_pile *a, t_pile *b)
{
	(void)a;
	(void)b;
	printf("cmd : %s\n", cmd);
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
		}
		free(cmd);
		cmd = NULL;
	}
	sorted_check(a, b);
	display_pile(a);
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
