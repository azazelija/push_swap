/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 00:23:18 by fculator          #+#    #+#             */
/*   Updated: 2019/11/23 00:23:20 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	t_stack		*stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	ac--;
	av++;
	if (ac == 1)
	{
		av = split_args_to_stack(stack, av, &ac);
	}
	initialization_stack(stack, ac);
	stack->print_com = 0;
	if (ac > 0)
	{
		write_args_to_stack(stack, av, ac);
		do_operation(stack);
		if (stack_is_sorted(stack) && stack->b_size == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		exit(1);
	free_stack(stack);
	return (0);
}
