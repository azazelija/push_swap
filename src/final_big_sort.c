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

void		spin_stack(t_stack *stack, t_solution sol)
{
	while (sol.num_ra-- > 0)
	{
		apply_ra(stack);
	}
	while (sol.num_rb-- > 0)
	{
		apply_rb(stack);
	}
	while (sol.num_rra-- > 0)
	{
		apply_rra(stack);
	}
	while (sol.num_rrb-- > 0)
	{
		apply_rrb(stack);
	}
	while (sol.num_rr-- > 0)
	{
		apply_rr(stack);
	}
	while (sol.num_rrr-- > 0)
	{
		apply_rrr(stack);
	}
}

void		final_sort(t_stack *stack, t_args *args)
{
	size_t		i;
	size_t		n;
	t_stack		*fal;
	t_stack		*fal_2;

	i = 0;
	n = 0;
	fal = init_2(stack);
	while (fal->a[0] != args->min_i)
	{
		apply_rra(fal);
		++i;
	}
	free_fal(fal);
	fal_2 = init_2(stack);
	while (fal_2->a[0] != args->min_i)
	{
		apply_ra(fal_2);
		++n;
	}
	free_fal(fal_2);
	final_norm_sort(stack, args, i, n);
}

void		final_norm_sort(t_stack *stack, t_args *args, int i, int n)
{
	if (i < n)
		while (stack->a[0] != args->min_i)
			apply_rra(stack);
	else
		while (stack->a[0] != args->min_i)
			apply_ra(stack);
}

t_stack		*init_2(t_stack *or)
{
	int			i;
	t_stack		*fal;

	fal = (t_stack *)malloc(sizeof(t_stack));
	fal->a = (int *)malloc(sizeof(int) * (or->a_size + 1));
	fal->b = (int *)ft_memalloc(sizeof(int) * (or->a_size + 1));
	i = -1;
	while (++i < or->a_size)
		fal->a[i] = or->a[i];
	fal->a_size = or->a_size;
	i = -1;
	while (++i < or->b_size)
		fal->b[i] = or->b[i];
	fal->b_size = or->b_size;
	fal->one_size = 0;
	fal->print_com = 0;
	fal->vis_com = 0;
	return (fal);
}

void		free_fal(t_stack *fal)
{
	free(fal->a);
	free(fal->b);
	free(fal);
	fal = NULL;
}
