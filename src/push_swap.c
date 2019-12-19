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

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	ac--;
	av++;
	if (ac == 1)
	{
		av = split_args_to_stack(stack, av, &ac);
	}
	initialization_stack(stack, ac);
	stack->print_com = 1;
	if (ac > 1)
	{
		write_args_to_stack(stack, av, ac);
		basic_sort(stack);
	}
	else
		exit(1);
	free_stack(stack);
	return (0);
}