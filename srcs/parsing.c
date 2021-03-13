#include "../include/pile.h"

char	**ft_join_tab(char **tab, char **tmp_tab)
{
	char	**new_tab;
	int		len;
	int		i;
	int		j;

	len = ft_tablen(tab) + ft_tablen(tmp_tab);
	if (!(new_tab = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < ft_tablen(tab))
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	j = 0;
	while (j < ft_tablen(tmp_tab))
	{
		new_tab[i + j] = ft_strdup(tmp_tab[j]);
		j++;
	}
	free_tab(tab);
	free_tab(tmp_tab);
	new_tab[i + j] = NULL;
	return (new_tab);
}

char	**parse_arg(char **av)
{
	char	**tab;
	char	**tmp_tab;
	int		i;

	i = 1;
	tab = ft_split(av[i], ' ');
	while (av[i] && av[i + 1])
	{
		tmp_tab = ft_split(av[i + 1], ' ');
		tab = ft_join_tab(tab, tmp_tab);
		i++;
	}
	return (tab);
}
