/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:16:17 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/06 15:00:14 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **s)
{
	t_stack	*node;

	if (!s || !*s || !(*s)->next)
		return ;
	node = (*s)->next;
	(*s)->next = (*s)->next->next;
	(*s)->prev = node;
	if ((*s)->next != NULL)
		(*s)->next->prev = *s;
	node->next = *s;
	node->prev = NULL;
	(*s) = node;
}

void	sa(t_stack **a, t_bench *bench)
{
	swap(a);
	write(1, "sa\n", 3);
	bench->sa++;
}

void	sb(t_stack **b, t_bench *bench)
{
	swap(b);
	write(1, "sb\n", 3);
	bench->sb++;
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	bench->ss++;
}
