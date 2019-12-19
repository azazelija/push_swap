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
	t_shift *top_shift;
	int 		optimize;

	optimize = (stack->a_size > 200)? 50 : 2;
	while (stack->b_size != 2)
		apply_pb(stack);
	while (stack->a_size > optimize)
	{
		top_shift_finder(stack, top_shift);
		while (top_shift->all_shift)
		{
			if (ft_strequ(top_shift->all_rotation, "rr"))
				apply_rr(stack);
			else
				apply_rrr(stack);
			top_shift->all_shift--;
		}
		process_moves(top_shift, stack);
		apply_pb(stack);
		free_shift(top_shift);
	}
	insert_leftover_to_b(stack);
	insert_back_in_a(stack);
}

void	free_shift(t_shift *shift)
{
	free(shift->a_rotation);
	free(shift->b_rotation);
	free(shift->all_rotation);
	free(shift);
	shift = NULL;
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
