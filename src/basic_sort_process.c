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

void	basic_sort(t_stack *stack)
{
	if (stack_is_sorted(stack) && stack->b_size == 0)
		return ;
	if (stack->a_size <= 3)
		return (sort_3_numbers_stack(stack));
	else
		big_sort(stack);
}

void	sort_3_numbers_stack(t_stack *stack)
{
	int 	max_el_index;

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

int 	find_max_el_index(int *a, int size)
{
	int 	max;
	int		i;
	int 	index;

	max = 0;
	i = -1;
	index = 0;

	while (++i < size)
		if (a[i] > max)
		{
			max = a[i];
			index = i;
		}
	return  (index);
}
