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

void 	from_a_to_b(t_stack *stack, t_args *args)
{
	int 			tmp;
	int 			pos;
	int 			code;

	pos = stack->a_size;
	while (pos-- || pos > 3)
	{
		tmp = stack->a[0];
		code = 1;
		if (tmp > args->min_i && tmp < args->mid_s)
		{
			apply_pb(stack);
			apply_rb(stack);
			code = 0;
		}
		else if (tmp >= args->mid_s && tmp <= args->mid_e && tmp != args->mid_i)
		{
			apply_pb(stack);
			code = 0;
		}
		else if ((tmp > args->mid_e && tmp <= args->max_i)
				 || (tmp == args->min_i || tmp == args->mid_i))
		{
			apply_ra(stack);
			code = 0;
		}
		if (code)
			apply_ra(stack);
	}
}

