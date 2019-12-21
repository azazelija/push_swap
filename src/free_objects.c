/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 00:23:18 by fculator          #+#    #+#             */
/*   Updated: 2019/11/23 00:23:20 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
	stack = NULL;
}

void	free_stack_and_args(t_stack *stack, t_args *args)
{
	free(stack->a);
	free(stack->b);
	free(stack);
	stack = NULL;
	free(args->arr);
	free(args);
	args = NULL;
}