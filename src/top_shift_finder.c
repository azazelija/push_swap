/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_shift_finder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:49:23 by fculator          #+#    #+#             */
/*   Updated: 2019/12/02 16:49:25 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	top_shift_finder(t_stack *stack, t_shift *top_shift)
{
	int 		i;
	t_shift		*shift;
	
	i = 0;
	while (i < stack->a_size)
	{
		initalize_shift(stack, shift, i);
		if (i == 0)
			top_shift = shift;
		else if (top_shift->counter_com > shift->counter_com)
		{
			free_shift(top_shift);
			top_shift = shift;
		}
		else
			free_shift(shift);
		i++;
	}
}

void	initalize_shift(t_stack *stack,t_shift *shift, int pos)
{
	shift = (t_shift *)malloc(sizeof(t_shift));
	shift->a_rotation = ft_strnew(3);
	shift->b_rotation = ft_strnew(3);
	shift->all_rotation = ft_strnew(3);
	shift->item = stack->a[pos];
	shift->a_shift = a_rotating_finding(stack->a_size, pos, &(shift->a_rotation));
	shift->b_shift = find_place_in_b(stack->b, stack->b_size,
									 stack->a[pos], &(shift->b_rotation));
	shift->all_shift = find_common(shift);
	shift->counter_com = shift->a_shift + shift->b_shift + shift->all_shift + 1;
}
