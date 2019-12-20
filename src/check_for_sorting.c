/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:30:38 by fculator          #+#    #+#             */
/*   Updated: 2019/11/25 19:30:57 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int 	stack_is_sorted(t_stack *stack)
{
	int 	i;

	i = -1;
	while (++i < stack->a_size - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
	}
	return (1);
}

void	do_operation(t_stack *stack)
{
	char 	*op;

	op = 0;
	while (get_next_line(0, &op) > 0)
	{
		if (!op)
			break ;
		if (!is_operation(op, stack))
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(stack);
			free(op);
			exit(0);
		}
		free(op);
		op = NULL;
	}
	free(op);
}

int 	is_operation(char *op, t_stack *stack)
{
	if (ft_strequ(op, "sa"))
		apply_sa(stack);
	else if (ft_strequ(op, "sb"))
		apply_sb(stack);
	else if (ft_strequ(op, "ss"))
		apply_ss(stack);
	else if (ft_strequ(op, "pa"))
		apply_pa(stack);
	else if (ft_strequ(op, "pb"))
		apply_pb(stack);
	else if (ft_strequ(op, "ra"))
		apply_ra(stack);
	else if (ft_strequ(op, "rb"))
		apply_rb(stack);
	else if (ft_strequ(op, "rr"))
		apply_rr(stack);
	else if (ft_strequ(op, "rra"))
		apply_rra(stack);
	else if (ft_strequ(op, "rrb"))
		apply_rrb(stack);
	else if (ft_strequ(op, "rrr"))
		apply_rrr(stack);
	else
		return (0);
	return (1);
}
