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

int		find_a_rot_type(int len, int pos, char **a_rot_type)
{
	if (pos > len / 2)
	{
		*a_rot_type = ft_strcpy(*a_rot_type, "rra");
		if (len > 2)
			pos = len - pos;
	}
	else
		*a_rot_type = ft_strcpy(*a_rot_type, "ra");
	return (pos);
}

int		find_b_rot_type(int len, int pos, char **b_rot_type)
{
	if (pos > len / 2)
	{
		*b_rot_type = ft_strcpy(*b_rot_type, "rrb");
		if (len > 2)
			pos = len - pos;
	}
	else
		*b_rot_type = ft_strcpy(*b_rot_type, "rb");
	return (pos);
}

int		find_place_in_b(int *stack, int len, int elem, char **rot_type)
{
	register int i;
	register int place;

	i = 0;
	place = 0;
	if (len == 2 && elem > stack[0] && elem < stack[len - 1])
		place = 0;
	else if (len == 2 && elem < stack[0] && elem > stack[len - 1])
		place = 1;
	else if (elem > stack[find_max_el_index(stack, len)] ||
			 elem < stack[find_min_el_index(stack, len)])
		place = find_max_el_index(stack, len);
	else
		while (i < len)
		{
			if (elem < stack[i] && ((i + 1 < len && elem > stack[i + 1]) ||
									(i + 1 == len && elem > stack[0])))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	return (find_b_rot_type(len, place, rot_type));
}

int		find_place_in_a(int *stack, int len, int elem, char **rot_type)
{
	register int i;
	register int place;

	i = 0;
	place = 0;
	if (len == 2 && elem > stack[0] && elem < stack[1])
		place = 1;
	else if (len == 2 && elem < stack[0] && elem > stack[1])
		place = 0;
	else if (elem > stack[find_max_el_index(stack, len)] || elem < stack[find_min_el_index(stack, len)])
		place = find_min_el_index(stack, len);
	else
		while (i < len)
		{
			if (elem > stack[i] && ((i + 1 < len && elem < stack[i + 1]) ||
									(i + 1 == len && elem < stack[0])))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	return (find_a_rot_type(len, place, rot_type));
}

int		find_common(t_moves *moves)
{
	register int		common;

	common = 0;
	if ((ft_strequ(moves->a_rot_type, "rra") && (ft_strequ(moves->b_rot_type , "rrb"))) ||
		(ft_strequ(moves->a_rot_type, "ra") && (ft_strequ(moves->b_rot_type , "rb"))))
	{
		common = (moves->a_moves > moves->b_moves ? moves->b_moves : moves->a_moves);
		if (common)
		{
			moves->common_rot = ft_strcpy(moves->common_rot, moves->a_rot_type);
			moves->common_rot[ft_strlen(moves->common_rot) - 1] = 'r';
			moves->b_moves -= common;
			moves->a_moves -= common;
		}
	}
	return (common);
}


