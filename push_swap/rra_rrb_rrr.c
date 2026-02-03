/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <yazeed.barakat@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:48:48 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/03 12:03:59 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(stack **a)
{
	stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = *a;
	last->prev = NULL;
	(*a)->prev = last;
	(*a) = last;
	write (1, "rra\n", 4);
}

void	rrb(stack **b)
{
	stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	last = *b;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = *b;
	last->prev = NULL;
	(*b)->prev = last;
	(*b) = last;
	write (1, "rrb\n", 4);
}

void	rrr(stack **a, stack **b)
{
	rra(a);
	rrb(b);
}
