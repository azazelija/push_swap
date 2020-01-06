/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <mstackvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:15:25 by fculator          #+#    #+#             */
/*   Updated: 2019/11/30 17:15:30 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		print_stack(t_stack *stack)
{
	int		i;

	write(1, "-----------------STACK A-----------------\n", 42);
	if (stack->a_size == 0)
		write(1, "*****************A EMPTY*****************\n", 42);
	i = -1;
	while (++i < stack->a_size)
	{
		ft_putnbr(stack->a[i]);
		write(1, "\n", 1);
	}
	write(1, "-----------------------------------------\n", 42);
	write(1, "-----------------STACK B-----------------\n", 42);
	if (stack->b_size == 0)
		write(1, "*****************B EMPTY*****************\n", 42);
	i = -1;
	while (++i < stack->b_size)
	{
		ft_putnbr(stack->b[i]);
		write(1, "\n", 1);
	}
	write(1, "-----------------------------------------\n", 42);
}

int			check_visual(t_stack *stack, int ac, char **av)
{
	int		i;

	i = -1;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-v") == 0)
		{
			stack->vis_com = 1;
			return (1);
		}
	}
	return (0);
}
