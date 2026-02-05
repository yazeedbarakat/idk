/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <yazeed.barakat@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:48:48 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/05 11:43:47 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **s)
{
	t_stack	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	last = *s;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = *s;
	last->prev = NULL;
	(*s)->prev = last;
	(*s) = last;
}

void	rra(t_stack **a, t_bench *bench)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	bench->rra++;
}

void	rrb(stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	bench->rrb++;
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	reverse_rotate(a);
	reverse_rotate(b);
	bench->rrr++;
}
