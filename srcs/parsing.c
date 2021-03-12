#include "../include/pile.h"

char	**ft_append_tab(char **tab, char *str)
{
	char	**tmp_tab;
	char	**new_tab;
	int		len;
	int		i;
	int		j;

	tmp_tab	= ft_split(str, ' ');
	len = ft_tablen(tab) + ft_tablen(tmp_tab);
	if (!(new_tab = malloc(sizeof(char *) * (len + 1))))
	{
		printf("Error: malloc failed\n");
		exit(1);
	}
	i = 0;
	while (i < ft_tablen(tab))
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	free_tab(tab);
	j = 0;
	while (j < ft_tablen(tmp_tab))
	{
		new_tab[i + j] = ft_strdup(tmp_tab[j]);
		j++;
	}
	free_tab(tmp_tab);
	new_tab[i + j] = NULL;
	return (new_tab);
}

char	**parse_arg(char **av)
{
	char	**tab;
	int		i;

	i = 1;
	tab = ft_split(av[i], ' ');
	while (av[i] && av[i + 1])
	{
		tab = ft_append_tab(tab, av[i + 1]);
		i++;
	}
	return (tab);
}
