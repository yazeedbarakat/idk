/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:16:17 by ybarakat          #+#    #+#             */
/*   Updated: 2026/01/23 20:08:00 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(stack **a)
{
	stack	*node;

	if (!a || !*a || !(*a)->next)
		return ;
	node = (*a)->next;
	(*a)->next = (*a)->next->next;
	(*a)->prev = node;
	if ((*a)->next != NULL)
		(*a)->next->prev = *a;
	node->next = *a;
	node->prev = NULL;
	(*a) = node;
}

void	sb(stack **b)
{
	stack	*node;

	if (!b || !*b || !(*b)->next)
		return ;
	node = (*b)->next;
	(*b)->next = (*b)->next->next;
	(*b)->prev = node;
	if ((*b)->next != NULL)
		(*b)->next->prev = *b;
	node->next = *b;
	node->prev = NULL;
	(*b) = node;
}

void	ss(stack **a, stack **b)
{
	sa(a);
	sb(b);
}
