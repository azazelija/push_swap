/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_to_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:32:23 by fculator          #+#    #+#             */
/*   Updated: 2019/11/25 18:32:26 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	initialization_stack(t_stack *stack, int ac)
{
	if (!(stack->a = (int *)malloc(sizeof(int) * ac)))
		exit(1);
	if (!(stack->b = (int *)ft_memalloc(sizeof(int) * ac)))
		exit(1);
	stack->a_size = ac - 1;
	stack->b_size = 0;
	stack->counter_com = 0;
}

void	write_args_to_stack(t_stack *stack, char **av, int ac)
{
	int		i;

	i = 0;
	if (!validate_args(av, ac))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(stack);
		exit(1);
	}
	while (++i < ac)
		stack->a[i - 1] = ft_atoi(av[i]);
}

int		validate_args(char **av, int ac)
{
	int		i;
	int		j;
	int 	k;

	i = 0;
	while (++i < ac)
	{
		j = i;
		k = 0;
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			return (0);
		while (av[++j])
		{
			if (ft_strequ(av[j], av[i]))
				return (0);
		}
		while (av[i][k])
		{
			if (!ft_isdigit(av[i][k++]))
				return (0);
		}
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
	stack = NULL;
}
