/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:04:18 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/16 01:04:19 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

char	*color_set_a(t_pile *a, char *cmd, int line_a)
{
	if ((!ft_strcmp(cmd, "sa") || !ft_strcmp(cmd, "ss"))
		&& line_a > (pile_length(a) - 2))
		return (YELLOW);
	else if (!ft_strcmp(cmd, "pa") && line_a == pile_length(a))
		return (YELLOW);
	else if ((!ft_strcmp(cmd, "ra") || !ft_strcmp(cmd, "rr")) && line_a == 1)
		return (YELLOW);
	else if ((!ft_strcmp(cmd, "rra") || !ft_strcmp(cmd, "rrr"))
		&& line_a == pile_length(a))
		return (YELLOW);
	else
		return (NULL);
}

char	*color_set_b(t_pile *b, char *cmd, int line_b)
{
	if ((!ft_strcmp(cmd, "sb") || !ft_strcmp(cmd, "ss"))
		&& line_b > (pile_length(b) - 2))
		return (YELLOW);
	else if (!ft_strcmp(cmd, "pb") && line_b == pile_length(b))
		return (YELLOW);
	else if ((!ft_strcmp(cmd, "rb") || !ft_strcmp(cmd, "rr")) && line_b == 1)
		return (YELLOW);
	else if ((!ft_strcmp(cmd, "rrb") || !ft_strcmp(cmd, "rrr"))
		&& line_b == pile_length(b))
		return (YELLOW);
	else
		return (NULL);
}

void	printf_line(int nb, int nb_max)
{
	int		i;
	int		n;

	n = (((float)nb / nb_max) * 16) + 1;
	i = 0;
	while (i < n)
	{
		printf("-");
		i++;
	}
	while (i < 22)
	{
		printf(" ");
		i++;
	}
}

void	print_stack(t_pile *stack, int line, int max, char *color)
{
	t_element	*current;
	int			stack_len;

	current = stack->first;
	stack_len = pile_length(stack);
	if (color != NULL)
		printf("%s", color);
	while (stack_len != line)
	{
		current = current->next;
		stack_len--;
	}
	printf("%-3d", current->nb);
	printf_line(current->nb, max);
	if (color != NULL)
		printf("%s", SET);
}

void	visual(t_pile *a, t_pile *b, char *cmd, int move)
{
	int		nb_max;
	int		nb_line;

	system("clear");
	nb_line = pile_length(a) + pile_length(b);
	nb_max = nb_line;
	while (nb_line > 0)
	{
		if (nb_line <= pile_length(a))
			print_stack(a, nb_line, nb_max, color_set_a(a, cmd, nb_line));
		else
			printf("%25s", "");
		if (nb_line <= pile_length(b))
			print_stack(b, nb_line, nb_max, color_set_b(b, cmd, nb_line));
		else
			printf("%25s", "");
		printf("\n");
		nb_line--;
	}
	printf("%s = %-15d", "STACK A", pile_length(a));
	printf("%s = %-15d\n", "STACK B", pile_length(b));
	printf("CMD: %s\n", cmd);
	printf("MOVE : %d\n", move);
	system("sleep 0.05");
}
