/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 20:34:13 by fculator          #+#    #+#             */
/*   Updated: 2019/12/02 20:34:14 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		a_rotating_finding(int len, int pos, char **a_rotation)
{
	if (pos > len / 2)
	{
		*a_rotation = ft_strcpy(*a_rotation, "rra");
		if (len > 2)
			pos = len - pos;
	}
	else
		*a_rotation = ft_strcpy(*a_rotation, "ra");
	return (pos);
}

int		b_rotating_finding(int len, int pos, char **b_rotation)
{
	if (pos > len / 2)
	{
		*b_rotation = ft_strcpy(*b_rotation, "rrb");
		if (len > 2)
			pos = len - pos;
	}
	else
		*b_rotation = ft_strcpy(*b_rotation, "rb");
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
	return (b_rotating_finding(len, place, rot_type));
}

int		find_common(t_shift *shift)
{
	register int		common;

	common = 0;
	if ((ft_strequ(shift->a_rotation, "rra") && (ft_strequ(shift->b_rotation , "rrb"))) ||
		(ft_strequ(shift->a_rotation, "ra") && (ft_strequ(shift->b_rotation , "rb"))))
	{
		common = (shift->a_shift > shift->b_shift ? shift->b_shift : shift->a_shift);
		if (common)
		{
			shift->all_rotation = ft_strcpy(shift->all_rotation, shift->a_rotation);
			shift->all_rotation[ft_strlen(shift->all_rotation) - 1] = 'r';
			shift->b_shift -= common;
			shift->a_shift -= common;
		}
	}
	return (common);
}
