/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:15:25 by fculator          #+#    #+#             */
/*   Updated: 2019/11/30 17:15:30 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	big_sort(t_stack *stack)
{
	t_moves	*best;
	int		opt;

	opt = (stack->a_size > 200)? 50 : 2;

	apply_pb(stack);
	apply_pb(stack);
	while (stack->a_size > opt) {
		best = best_way_from_a_to_b(stack);
		while (best->common_moves)
		{
			if (ft_strequ(best->common_rot, "rr"))
				apply_rr(stack);
			else
				apply_rrr(stack);
			best->common_moves--;
		}
		process_moves(best, stack);
		apply_pb(stack);
		free_moves(best);
	}
	insert_leftover_to_b(stack);
	insert_back_in_a(stack);
}

int 	find_min_el_index(int *a, int size)
{
	int 	min;
	int		i;
	int 	index;

	min = INT_MAX;
	i = -1;
	index = 0;

	while (++i < size)
		if (a[i] < min)
		{
			min = a[i];
			index = i;
		}
	return  (index);
}

void	process_moves(t_moves *best_move, t_stack *stack)
{
	while (best_move->a_moves)
	{
		if (ft_strequ(best_move->a_rot_type, "ra"))
			apply_ra(stack);
		else
			apply_rra(stack);
		best_move->a_moves--;
	}
	while (best_move->b_moves)
	{
		if (ft_strequ(best_move->b_rot_type, "rb"))
			apply_rb(stack);
		else
			apply_rrb(stack);
		best_move->b_moves--;
	}
}

void	insert_leftover_to_b(t_stack *stack)
{
	int idx;

	idx = 0;
	while (stack->a_size > 2)
	{
		idx = find_min_el_index(stack->a, stack->a_size);
		if (idx == 0)
			apply_pb(stack);
		else if (idx <= stack->a_size / 2)
			apply_ra(stack);
		else if (idx > stack->a_size / 2)
			apply_rra(stack);
	}
}