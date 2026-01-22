/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <yazeed.barakat@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:48:48 by ybarakat          #+#    #+#             */
/*   Updated: 2026/01/22 16:11:56 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rra(p_list **a)
{
	p_list	*last;

	last = *a;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = *a;
	last->prev = NULL;
	(*a)->prev = last;
	(*a) = last;
}

void	rrb(p_list **b)
{
	p_list	*last;

	last = *b;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = *b;
	last->prev = NULL;
	(*b)->prev = last;
	(*b) = last;
}

void	rrr(p_list **a, p_list **b)
{
	rra(a);
	rrb(b);
}
