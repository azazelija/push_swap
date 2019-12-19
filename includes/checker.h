/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:22:07 by fculator          #+#    #+#             */
/*   Updated: 2019/11/25 18:22:36 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# define BUFF_SIZE 32
# define FD_MAX 255

typedef struct		s_stack
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	int 	counter_com;
	int		print_com;
}					t_stack;

typedef struct	s_moves
{
	int			elem;
	int			a_moves;
	char		*a_rot_type;
	char		*b_rot_type;
	char		*common_rot;
	int			b_moves;
	int			common_moves;
	int			total;
}				t_moves;

void				free_stack(t_stack *stack);
int					get_next_line(const int fd, char **line);
void				initialization_stack(t_stack *stack, int ac);
void				write_args_to_stack(t_stack *stack, char **av, int ac);
int					validate_args(char **av, int ac);
int 				stack_is_sorted(t_stack *stack);
void				do_operation(t_stack *stack);
int 				is_operation(char *op, t_stack *stack);
void				apply_sa(t_stack *stack);
void				apply_sb(t_stack *stack);
void				apply_ss(t_stack *stack);
void				apply_pa(t_stack *stack);
void				apply_pb(t_stack *stack);
void				apply_ra(t_stack *stack);
void				apply_rb(t_stack *stack);
void				apply_rr(t_stack *stack);
void				apply_rra(t_stack *stack);
void				apply_rrb(t_stack *stack);
void				apply_rrr(t_stack *stack);
/*PUSH_SWAP*/
void				basic_sort(t_stack *stack);
void				sort_3_numbers_stack(t_stack *stack);
void				big_sort(t_stack *stack);
int 				find_max_el_index(int *a, int size);
int 				find_min_el_index(int *a, int size);
t_moves				*best_way_from_a_to_b(t_stack *stack);
t_moves				*find_move_from_a_to_b(t_stack *stack, int i);
int					find_a_rot_type(int len, int pos, char **a_rot_type);
int					find_b_rot_type(int len, int pos, char **b_rot_type);
int					find_place_in_b(int *stack, int len, int elem, char **rot_type);
int					find_common(t_moves *moves);
void				free_moves(t_moves *moves);
void				process_moves(t_moves *best_move, t_stack *stack);
void				insert_leftover_to_b(t_stack *stack);
void				insert_back_in_a(t_stack *stack);
int					find_place_in_a(int *stack, int len, int elem, char **rot_type);
void				place_smallest_first_a(t_stack *stack);

#endif
