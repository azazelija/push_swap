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

t_solution		check_stack_b(t_stack *stack)
{
	t_solution			best_sol;
	t_solution			cur_sol;
	size_t				size;
	size_t				i;

	ft_bzero(&best_sol, sizeof(t_solution));
	ft_bzero(&cur_sol, sizeof(t_solution));
	i = 0;
	size = stack->b_size;
	best_sol = get_solution(stack, stack->b[i], i);
	while (i < size)
	{
		cur_sol = get_solution(stack, stack->b[i], i);
		if (cur_sol.num_all < best_sol.num_all)
			best_sol = cur_sol;
		++i;
	}
	return (best_sol);
}

t_solution		get_solution(t_stack *stack, int num, size_t i)
{
	t_solution			solve[4];
	t_direction			cur_dir;
	t_direction			best_dir;
	int					min_cmd;

	ft_bzero(solve, sizeof(t_solution) * 4);
	first_step(solve, i, stack, num);
	second_step(solve, i, stack, num);
	cur_dir = FIRST;
	min_cmd = solve[FIRST].num_all;
	best_dir = cur_dir;
	while (cur_dir <= LAST)
	{
		if (solve[cur_dir].num_all < min_cmd)
		{
			best_dir = cur_dir;
			min_cmd = solve[cur_dir].num_all;
		}
		cur_dir++;
	}
	return (solve[best_dir]);
}
