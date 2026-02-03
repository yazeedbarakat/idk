/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:19:12 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/03 12:02:42 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(stack **a)
{
	stack	*top;
	stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	top = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = top;
	top->prev = last;
	top->next = NULL;
	write (1, "ra\n", 3);
}

void	rb(stack **b)
{
	stack  *top;
	stack  *last;
	
	if (!b || !*b || !(*b)->next)
		return ;
	top = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = top;
	top->prev = last;
	top->next = NULL;
	write (1, "rb\n", 3);
}

void	rr(stack **a, stack **b)
{
	ra(a);
	rb(b);
}
