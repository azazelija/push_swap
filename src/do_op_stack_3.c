/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_stack_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:35:43 by fculator          #+#    #+#             */
/*   Updated: 2019/11/25 19:35:44 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	apply_rrr(t_stack *stack)
{
	int		tmp;

	tmp = stack->print_com;
	stack->print_com = 0;
	apply_rra(stack);
	apply_rrb(stack);
	if (tmp != 0)
		stack->print_com = 1;
	stack->print_com ? write(1, "rrr\n", 4) : 0;
	stack->counter_com++;
}
