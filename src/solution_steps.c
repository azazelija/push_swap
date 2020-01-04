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

void	first_step(t_solution *solve, size_t i, t_stack *s, int num)
{
	solve[UP].num_rb = i;
	solve[UP].num_ra = get_insert_index(s, num);
	solve[UP].num_rr = (solve[UP].num_rb > solve[UP].num_ra ?
						solve[UP].num_ra : solve[UP].num_rb);
	solve[UP].num_ra -= solve[UP].num_rr;
	solve[UP].num_rb -= solve[UP].num_rr;
	solve[UP].num_all = solve[UP].num_ra + solve[UP].num_rb + solve[UP].num_rr;
	solve[DOWN].num_rra = s->a_size - get_insert_index(s, num);
	solve[DOWN].num_rrb = s->b_size - i;
	solve[DOWN].num_rrr = (solve[DOWN].num_rrb > solve[DOWN].num_rra ?
	solve[DOWN].num_rra : solve[DOWN].num_rrb);
	solve[DOWN].num_rra -= solve[DOWN].num_rrr;
	solve[DOWN].num_rrb -= solve[DOWN].num_rrr;
	solve[DOWN].num_all = solve[DOWN].num_rra + solve[DOWN].num_rrb +
	solve[DOWN].num_rrr;
}

void	second_step(t_solution *solve, size_t i, t_stack *s, int num)
{
	solve[UP_DOWN].num_ra = get_insert_index(s, num);
	solve[UP_DOWN].num_rrb = s->b_size - i;
	solve[UP_DOWN].num_all = solve[UP_DOWN].num_ra + solve[UP_DOWN].num_rrb;
	solve[DOWN_UP].num_rra = s->a_size - get_insert_index(s, num);
	solve[DOWN_UP].num_rb = i;
	solve[DOWN_UP].num_all = solve[DOWN_UP].num_rra + solve[DOWN_UP].num_rb;
}

int		get_insert_index(t_stack *stack, int num)
{
	size_t		i;

	i = 0;
	while (stack->a[i] < num || (i > 0 && stack->a[i - 1] > num) ||
	(i == 0 && stack->a[stack->a_size - 1] > num))
	{
		i++;
	}
	return (i);
}
