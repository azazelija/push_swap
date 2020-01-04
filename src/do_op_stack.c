/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:31:26 by fculator          #+#    #+#             */
/*   Updated: 2019/11/25 19:31:30 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	apply_sa(t_stack *stack)
{
	int		tmp;

	if (stack->a_size < 2)
		return ;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	stack->print_com ? write(1, "sa\n", 3) : 0;
	stack->counter_com++;
}

void	apply_sb(t_stack *stack)
{
	int		tmp;

	if (stack->b_size < 2)
		return ;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	stack->print_com ? write(1, "sb\n", 3) : 0;
	stack->counter_com++;
}

void	apply_ss(t_stack *stack)
{
	int		tmp;

	tmp = stack->print_com;
	stack->print_com = 0;
	apply_sa(stack);
	apply_sb(stack);
	if (tmp != 0)
		stack->print_com = 1;
	stack->print_com ? write(1, "ss\n", 3) : 0;
	stack->counter_com++;
}

void	apply_pa(t_stack *stack)
{
	int		i;

	if (stack->b_size == 0)
		return ;
	i = stack->a_size;
	while (i-- > 0)
		stack->a[i + 1] = stack->a[i];
	stack->a[0] = stack->b[0];
	i = 0;
	while (i++ <= stack->b_size - 1)
		stack->b[i - 1] = stack->b[i];
	stack->a_size++;
	stack->b_size--;
	stack->print_com ? write(1, "pa\n", 3) : 0;
	stack->counter_com++;
}

void	apply_pb(t_stack *stack)
{
	int		i;

	if (stack->a_size == 0)
		return ;
	i = stack->b_size;
	while (i-- > 0)
		stack->b[i + 1] = stack->b[i];
	stack->b[0] = stack->a[0];
	i = 0;
	while (i++ <= stack->a_size - 1)
		stack->a[i - 1] = stack->a[i];
	stack->b_size++;
	stack->a_size--;
	stack->print_com ? write(1, "pb\n", 3) : 0;
	stack->counter_com++;
}
