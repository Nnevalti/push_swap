/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:15:42 by vdescham          #+#    #+#             */
/*   Updated: 2021/03/15 18:15:44 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdio.h>
# include <stdlib.h>
# include "../libft/include/libft.h"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define SET "\033[0m"

typedef enum			e_bool
{
	FALSE,
	TRUE
}						t_bool;

typedef struct			s_element
{
	int					nb;
	struct s_element	*next;
}						t_element;

typedef struct			s_pile
{
	t_element			*first;
}						t_pile;

typedef struct			s_sort
{
	int		move_in_a;
	int		move_in_b;
	int		move_in_both;
	t_bool	rotate_r_in_a;
	t_bool	rotate_r_in_b;
	int		total_move;
}						t_move;

typedef struct			s_flags
{
	t_bool		reverse;
	t_bool		visual;
}						t_flags;

/*
** FLAGS.C
*/
t_flags					*init_flags(void);
int						check_for_flags_checker(char **av, t_flags *flags);

/*
** PARSING.C
*/
char					**parse_arg(char **av, int ac, t_flags *flags);

/*
** CHECK_ARG.C
*/
void					check_arg(char **tab, t_flags *flags);

/*
**	STACK.C
*/
t_pile					*init_pile();
void					empiler(t_pile *stack, int nb);
int						depiler(t_pile *stack);
int						pile_length(t_pile *stack);
void					display_pile(t_pile *stack);

/*
** SORT.C
*/
void					sort_pile(t_pile *a, t_pile *b);
/*
** SORT_REVERSE.C
*/
void					sort_pile_reverse(t_pile *a, t_pile *b);

/*
** SORT_UTILS.C
*/
void					rotate_n_times(t_pile *a, t_pile *b, int pos);
int						find_biggest_nb_pos(t_pile *stack);
int						find_smallest_nb_pos(t_pile *stack);
int						find_min_nb(t_pile *stack);
int						find_max_nb(t_pile *stack);

/*
** SORT_UTILS2.C
*/
int						find_place_in_pile_ascending(int nb, t_pile *stack);
int						find_place_in_pile_descending(int nb, t_pile *stack);
void					final_rotate(t_pile *a, t_pile *b);
void					push_back_in_a(t_pile *a, t_pile *b);
void					push_back_in_a_r(t_pile *a, t_pile *b);

/*
** SORTED_CHECK.C
*/
void					sorted_check(t_pile *a, t_pile *b);
int						sorted_check_ps(t_pile *a, t_pile *b);

/*
** SORTED_CHECK_REVERSE.C
*/
void					sorted_check_r(t_pile *a, t_pile *b);
int						sorted_check_r_ps(t_pile *a, t_pile *b);

/*
** MOVE.C
*/
void					set_move_in_both(t_move *move);
void					copy_move_to_best_move(t_move *move, t_move *best_move);
t_move					*best_move_a_to_b(t_pile *a, t_pile *b);

/*
** MOVE_REVERSE.C
*/
t_move					*best_move_a_to_b_r(t_pile *a, t_pile *b);

/*
** MOVE_UTILS.C
*/
t_move					*init_move(void);
void					move_in_a(t_move *move, int pos, t_pile *a);
void					move_in_b(t_move *move, int nb, t_pile *b);

/*
** MOVE_UTILS_REVERSE.C
*/
void					move_in_a_r(t_move *move, int pos, t_pile *a);
void					move_in_b_r(t_move *move, int nb, t_pile *b);

/*
** EXEC_CMD.C
*/
int						exec_cmd(char *cmd, t_pile *a, t_pile *b);
void					sort_exec(char *cmd, t_pile *a, t_pile *b);
void					exec_best_move(t_move *best_move, t_pile *a, t_pile *b);

/*
** OPERATION.C
*/
void					push_nb(t_pile *from, t_pile *to);
void					swap_nb(t_pile *stack);
void					rotate_nb(t_pile *stack, int len);
void					reverse_rotate_nb(t_pile *stack, int len);

/*
** FREE.C
*/
void					free_pile(t_pile *stack);
void					free_tab(char **tab);
void					free_move(t_move *sort);

/*
** VISUAL.C
*/
void					visual(t_pile *a, t_pile *b, char *cmd, int move);
void					print_stack(t_pile *stack, int line, int max,
							char *color);
void					pile_sorted_visual(t_pile *a, t_pile *b, int move,
							t_bool reverse);

#endif
