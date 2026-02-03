/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabaraka <sabaraka@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:20:05 by sabaraka          #+#    #+#             */
/*   Updated: 2026/02/03 12:01:50 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(stack **a, stack **b)
{
	stack	*top_b;
	stack	*top_a;

	if (!b || !*b)
		return;
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
	write (1, "pa\n", 3);
}

void	pb(stack **a, stack **b)
{
	stack	*top_b;
	stack	*top_a;

	if (!a || !*a)
		return;
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
	write (1, "pb\n", 3);
}
