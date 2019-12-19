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

typedef struct	s_shift
{
	int			item;
	int			a_shift;
	int			b_shift;
	int			all_shift;
	char		*a_rotation;
	char		*b_rotation;
	char		*all_rotation;
	int			counter_com;
}				t_shift;

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
void				free_shift(t_shift *shift);
void				top_shift_finder(t_stack *stack, t_shift *shift);
void				initalize_shift(t_stack *stack,t_shift *shift, int pos);
int					a_rotating_finding(int len, int pos, char **a_rot_type);
int					b_rotating_finding(int len, int pos, char **b_rot_type);
int					find_place_in_b(int *stack, int len, int elem, char **rot_type);
int					find_common(t_shift *moves);


#endif
