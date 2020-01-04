/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 22:38:47 by fculator          #+#    #+#             */
/*   Updated: 2019/11/25 22:38:49 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	basic_sort(t_stack *stack, t_args *args)
{
	if (stack_is_sorted(stack) && stack->b_size == 0)
		return ;
	if (stack->a_size <= 3)
		return (sort_3_numbers_stack(stack));
	else if (stack->a_size <= 5)
		small_sort_stack(stack);
	else
		big_sort(stack, args);
}

void	sort_3_numbers_stack(t_stack *stack)
{
	int		max_el_index;

	if (stack->a_size == 1)
		return ;
	if (stack->a_size == 2)
	{
		if (stack->a[0] > stack->a[1])
			apply_sa(stack);
	}
	else if (stack->a_size == 3)
	{
		max_el_index = find_max_el_index(stack->a, stack->a_size);
		if (max_el_index == 0)
			apply_ra(stack);
		if (max_el_index == 1)
			apply_rra(stack);
		if (stack->a[0] > stack->a[1])
			apply_sa(stack);
	}
}

void	small_sort_stack(t_stack *stack)
{
	int *max;

	max = find_max_elems(stack->a, stack->a_size);
	while (stack->a_size > 3)
	{
		if (stack->a[0] < max[2])
			apply_pb(stack);
		else
			apply_ra(stack);
	}
	sort_3_numbers_stack(stack);
	push_back_to_a(stack);
	free(max);
}

void	push_back_to_a(t_stack *stack)
{
	int *max;

	max = find_max_elems(stack->b, stack->b_size);
	while (stack->b_size > 0)
	{
		if (stack->b[0] == max[0])
		{
			apply_pa(stack);
			apply_pa(stack);
		}
		else if (stack->b[0] == max[1])
		{
			apply_sb(stack);
		}
	}
	free(max);
}
