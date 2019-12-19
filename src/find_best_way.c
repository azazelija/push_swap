/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:15:25 by fculator          #+#    #+#             */
/*   Updated: 2019/11/30 17:15:30 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_moves	*best_way_from_a_to_b(t_stack *stack)
{
	int		i;
	t_moves	*best;
	t_moves *move;

	i = 0;
	while (i < stack->a_size)
	{
		move = find_move_from_a_to_b(stack, i);
		if (i == 0)
			best = move;
		else if (best->total > move->total)
		{
			free_moves(best);
			best = move;
		}
		else
			free_moves(move);
		i++;
	}
	return (best);
}

t_moves *find_move_from_a_to_b(t_stack *stack, int i)
{
	t_moves		*move;

	move = (t_moves *)malloc(sizeof(t_moves));
	move->a_rot_type = ft_strnew(3);
	move->b_rot_type = ft_strnew(3);
	move->common_rot = ft_strnew(3);
	move->elem = stack->a[i];
	move->a_moves = find_a_rot_type(stack->a_size, i, &(move->a_rot_type));
	move->b_moves = find_place_in_b(stack->b, stack->b_size,
									 stack->a[i], &(move->b_rot_type));
	move->common_moves = find_common(move);
	move->total = move->a_moves + move->b_moves + move->common_moves + 1;
	return (move);
}

void	free_moves(t_moves *moves)
{
	free(moves->a_rot_type);
	free(moves->b_rot_type);
	free(moves->common_rot);
	free(moves);
	moves = NULL;
}