/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_stack_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:33:52 by fculator          #+#    #+#             */
/*   Updated: 2019/11/25 19:33:53 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	apply_ra(t_stack *stack)
{
	int 	i;
	int		tmp;

	if (stack->a_size == 0)
		return ;
	i = 1;
	tmp = stack->a[0];
	while (i < stack->a_size)
	{
		stack->a[i - 1] = stack->a[i];
		i++;
	}
	stack->a[i - 1] = tmp;
	stack->print_com ? write(1, "ra\n", 3) : 0;
	stack->counter_com++;
}

void	apply_rb(t_stack *stack)
{
	int 	i;
	int		tmp;

	if (stack->b_size == 0)
		return ;
	i = 1;
	tmp = stack->b[0];
	while (i < stack->b_size)
	{
		stack->b[i - 1] = stack->b[i];
		i++;
	}
	stack->b[i - 1] = tmp;
	stack->print_com ? write(1, "rb\n", 3) : 0;
	stack->counter_com++;
}

void	apply_rr(t_stack *stack)
{
	int 	tmp;

	tmp = stack->print_com;
	stack->print_com = 0;

	apply_ra(stack);
	apply_rb(stack);
	if (tmp != 0)
		stack->print_com = 1;
	stack->print_com ? write(1, "rr\n", 3) : 0;
	stack->counter_com++;
}

void	apply_rra(t_stack *stack)
{
	int 	i;
	int 	tmp;

	if (stack->a_size == 0)
		return ;
	i = stack->a_size - 1;
	tmp = stack->a[i];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
	stack->print_com ? write(1, "rra\n", 4) : 0;
	stack->counter_com++;
}

void	apply_rrb(t_stack *stack)
{
	int 	i;
	int 	tmp;

	if (stack->b_size == 0)
		return ;
	i = stack->b_size - 1;
	tmp = stack->b[i];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
	stack->print_com ? write(1, "rrb\n", 4) : 0;
	stack->counter_com++;
}
