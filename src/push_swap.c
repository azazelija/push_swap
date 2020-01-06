/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 22:09:15 by fculator          #+#    #+#             */
/*   Updated: 2019/11/25 22:09:18 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	t_stack		*stack;
	t_args		*args;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))) ||
		!(args = (t_args *)malloc(sizeof(t_args))))
		exit(1);
	ac--;
	av++;
	if (ac == 1 || (check_visual(stack, ac, av) && ac == 2))
		av = split_args_to_stack(stack, av, &ac);
	else
		stack->one_size = 0;
	initialization_stack(stack, ac);
	initialization_args(args, ac);
	stack->print_com = 1;
	if (ac > 1)
	{
		write_args_to_stack(stack, av, ac);
		basic_sort(stack, args);
	}
	else
		exit(1);
	free_stack_and_args(stack, args);
	return (0);
}
