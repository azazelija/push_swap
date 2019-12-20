/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 22:38:47 by fculator          #+#    #+#             */
/*   Updated: 2019/11/25 22:38:49 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int 	find_max_el_index(int *stack, int size)
{
	int 	max_elems;
	int		i;
	int 	index;

	max_elems = 0;
	i = -1;
	index = 0;

	if (size == 0)
		return (-1);
	while (++i < size)
		if (stack[i] > max_elems)
		{
			max_elems = stack[i];
			index = i;
		}
	return  (index);
}

int 	find_min_el_index(int *stack, int size)
{
	int 	min;
	int		i;
	int 	index;

	if (size == 0)
		return (-1);
	min = INT_MAX;
	i = -1;
	index = 0;

	while (++i < size)
		if (stack[i] < min)
		{
			min = stack[i];
			index = i;
		}
	return  (index);
}

int 	*find_max_elems(int *stack, int size)
{
	int		*max_elems;


	max_elems = (int*)malloc(sizeof(int) * 3);
	max_elems[0] = stack[0];
	max_elems[1] = stack[find_min_el_index(stack, size)];
	max_elems[2] = max_elems[1];
	while (--size > 0)
		if (max_elems[0] < stack[size])
		{
			max_elems[2] = max_elems[1];
			max_elems[1] = max_elems[0];
			max_elems[0] = stack[size];
		}
		else if (max_elems[1] < stack[size])
		{
			max_elems[2] = max_elems[1];
			max_elems[1] = stack[size];
		}
		else if (max_elems[2] < stack[size])
			max_elems[2] = stack[size];
	return (max_elems);
}

