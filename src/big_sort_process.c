/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <mstackvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:15:25 by fculator          #+#    #+#             */
/*   Updated: 2019/11/30 17:15:30 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	big_sort(t_stack *stack, t_args *args)
{
	args_to_array(stack, args);
	from_a_to_b(stack, args);
	big_sort_process(stack, args);
}

void	big_sort_process(t_stack *stack, t_args *args)
{
	leave_3_nbrs_in_a(stack, args);
	sort_3_numbers_stack(stack);
	sort_stack_hard(stack, args);
}

void	leave_3_nbrs_in_a(t_stack *stack, t_args *args)
{
	int			code;
	int			i;
	int 		tmp;

	i = stack->a_size;
	while (i--)
	{
		tmp = stack->a[0];
		code = 1;
		if (tmp != args->max_i && tmp != args->mid_i
			&& tmp != args->min_i)
		{
			apply_pb(stack);
			code = 0;
		}
		if (code)
		{
			apply_ra(stack);
		}
	}
}

void	sort_stack_hard(t_stack *stack, t_args *args)
{
	t_solution			sol;

	while (stack->b_size)
	{
		sol = check_stack_b(stack);
		spin_stack(stack, sol);
		apply_pa(stack);
	}
	final_sort(stack, args);
}