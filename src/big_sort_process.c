/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <mstackvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:15:25 by fculator          #+#    #+#             */
/*   Updated: 2019/11/30 17:15:30 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	big_sort(t_stack *stack, t_args *args)
{
	args_to_array(stack, args);
	from_a_to_b(stack, args);
}