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
#include <stdio.h>

void		print_stack(t_stack *stack)
{
	printf("-----------------STACK A----------------------\n");
	if (stack->a_size == 0)
		printf("*************A empty**********************\n");
	for (int i = 0; i < stack->a_size; i++) {
		printf("%d\n", stack->a[i]);
	}
	printf("----------------------------------------------\n");
	printf("-----------------STACK B----------------------\n");
	if (stack->b_size == 0)
		printf("*************B empty**********************\n");
	for (int i = 0; i < stack->b_size; i++) {
		printf("%d\n", stack->b[i]);
	}
	printf("----------------------------------------------\n");
}

void		print_solution(t_solution *sol)
{
	printf("all = %d\t", sol->num_all);
	printf("ra = %d\t", sol->num_ra);
	printf("rb = %d\t", sol->num_rb);
	printf("rr = %d\t", sol->num_rr);
	printf("rra = %d\t", sol->num_rra);
	printf("rrb = %d\t", sol->num_rrb);
	printf("rrr = %d\t", sol->num_rrr);
	printf("\n");
}

