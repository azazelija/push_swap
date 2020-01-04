/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <mstackvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:15:25 by fculator          #+#    #+#             */
/*   Updated: 2019/11/30 17:15:30 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		spin_stack(t_stack *stack, t_solution sol)
{
	while (sol.num_ra-- > 0)
	{
		apply_ra(stack);
	}
	while (sol.num_rb-- > 0)
	{
		apply_rb(stack);
	}
	while (sol.num_rra-- > 0)
	{
		apply_rra(stack);
	}
	while (sol.num_rrb-- > 0)
	{
		apply_rrb(stack);
	}
	while (sol.num_rr-- > 0)
	{
		apply_rr(stack);
	}
	while (sol.num_rrr-- > 0)
	{
		apply_rrr(stack);
	}
}

void		final_sort(t_stack *stack, t_args *args)
{
	size_t		i;
	size_t		n;
	t_stack		*stack_a;
	t_stack		*stack_a2;

	i = 0;
	n = 0;
	stack_a = stack;
	stack_a2 = stack;
	while (stack_a->a[0] != args->min_i)
	{
		apply_rra(stack_a);
		++i;
	}
	while (stack_a2->a[0] != args->min_i)
	{
		apply_ra(stack_a2);
		++n;
	}
	if (i < n)
		while (stack->a[0] != args->min_i)
			apply_rra(stack);
	else
		while (stack->a[0] != args->min_i)
			apply_ra(stack);
}
