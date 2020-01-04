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

void		args_to_array(t_stack *stack, t_args *args)
{
	int		i;

	i = -1;
	while (++i < stack->a_size)
	{
		args->arr[i] = stack->a[i];
	}
	bubble_sort_arr_args(args, stack->a_size);
}

void		bubble_sort_arr_args(t_args *args, int size)
{
	int				i;
	int				sort;

	sort = 0;
	while (sort == 0)
	{
		sort = 1;
		i = 1;
		while (i < size)
		{
			if (args->arr[i - 1] > args->arr[i])
			{
				ft_swap(&args->arr[i - 1], &args->arr[i]);
				sort = 0;
			}
			++i;
		}
	}
	init_args_local(args, size);
}

void		init_args_local(t_args *args, int size)
{
	args->min_i = args->arr[0];
	args->mid_s = args->arr[size / 3];
	args->mid_e = args->arr[size * 2 / 3];
	args->mid_i = args->mid_s + ((args->mid_e - args->mid_s) / 2);
	args->max_i = args->arr[size - 1];
}
