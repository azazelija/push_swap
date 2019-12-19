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

void	insert_back_in_a(t_stack *stack)
{
	register int	num_of_rots;
	char			*rot_type;

	num_of_rots = 0;
	rot_type = ft_strnew(3);
	while (stack->b_size)
	{
		num_of_rots = find_place_in_a(stack->a,
									  stack->a_size, stack->b[0], &rot_type);
		while (num_of_rots > 0)
		{
			if (ft_strequ(rot_type, "ra"))
				apply_ra(stack);
			else
				apply_rra(stack);
			num_of_rots--;
		}
		apply_pa(stack);
	}
	place_smallest_first_a(stack);
	free(rot_type);
}

void	place_smallest_first_a(t_stack *stack)
{
	register int min_index;

	min_index = find_min_el_index(stack->a, stack->a_size);
	if (min_index <= stack->a_size / 2)
		while (min_index--)
			apply_ra(stack);
	else
		while ((stack->a_size - min_index) > 0)
		{
			apply_rra(stack);
			min_index++;
		}
}


