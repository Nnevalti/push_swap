/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:06:37 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/12 12:24:20 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILE_H
# define PILE_H
# include <stdio.h>
# include <stdlib.h>
# include "../libft/include/libft.h"

typedef struct			s_element
{
	int					nb;
	struct s_element	*next;
}						t_element;

typedef struct			s_pile
{
	t_element			*first;
}						t_pile;

/*
** CHECK_ARG.C
*/
void					check_arg(char **av);

/*
** PARSING.C
*/
char					**parse_arg(char **av);

/*
**	PILE.C
*/
t_pile					*init_pile();
void					empiler(t_pile *pile, int nb);
int						depiler(t_pile *pile);
int						pile_length(t_pile *pile);
void					display_pile(t_pile *pile);

/*
** SORTED_CHECK.C
*/
void					sorted_check(t_pile *a, t_pile *b);
int						sorted_check_ps(t_pile *a, t_pile *b);

/*
** EXEC_CMD.C
*/
int						exec_cmd(char *cmd, t_pile *a, t_pile *b);
void					sort_exec(char *cmd, t_pile *a, t_pile *b);

/*
** OPERATION.C
*/
void					push_nb(t_pile *from, t_pile *to);
void					swap_nb(t_pile *pile);
void					rotate_nb(t_pile *pile, int len);
void					reverse_rotate_nb(t_pile *pile, int len);
/*
** SORT.C
*/
void					sort_pile(t_pile *a, t_pile *b);

/*
** FREE.C
*/
void					free_pile(t_pile *pile);
void					free_tab(char **tab);

#endif
