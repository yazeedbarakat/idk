/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:19:12 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/05 11:43:06 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **s)
{
	t_stack	*top;
	t_stack	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	top = *s;
	*s = (*s)->next;
	(*s)->prev = NULL;
	last = *s;
	while (last->next)
		last = last->next;
	last->next = top;
	top->prev = last;
	top->next = NULL;
}

void	ra(t_stack **a, t_bench *bench)
{
	rotate(a);
	write(1, "ra\n", 3);
	bench->ra++;
}

void	rb(t_stack **b, t_bench *bench)
{
	rotate(b);
	write(1, "rb\n", 3);
	bench->rb++;
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	bench->rr++;
}
