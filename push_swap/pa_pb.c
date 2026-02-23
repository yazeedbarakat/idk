/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabaraka <sabaraka@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:20:05 by sabaraka          #+#    #+#             */
/*   Updated: 2026/02/08 08:46:02 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*top_b;
	t_stack	*top_a;

	if (!b || !*b)
		return ;
	top_a = *b;
	top_b = (*b)->next;
	*b = top_b;
	if (top_b)
		top_b->prev = NULL;
	if (*a)
		(*a)->prev = top_a;
	top_a->next = *a;
	top_a->prev = NULL;
	*a = top_a;
	write(1, "pa\n", 3);
	bench->pa++;
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*top_b;
	t_stack	*top_a;

	if (!a || !*a)
		return ;
	top_b = *a;
	top_a = (*a)->next;
	*a = top_a;
	if (top_a)
		top_a->prev = NULL;
	if (*b)
		(*b)->prev = top_b;
	top_b->next = *b;
	top_b->prev = NULL;
	*b = top_b;
	write(1, "pb\n", 3);
	bench->pb++;
}
