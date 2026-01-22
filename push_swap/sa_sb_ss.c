/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:16:17 by ybarakat          #+#    #+#             */
/*   Updated: 2026/01/22 14:44:11 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_stack(p_list **stack)
{
	p_list	*node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	(*stack)->prev = node;
	if ((*stack)->next != NULL)
		(*stack)->next->prev = *stack;
	node->next = *stack;
	node->prev = NULL;
	(*stack) = node;
}

void	ss_stack(p_list **a, p_list **b)
{
	s_stack(a);
	s_stack(b);
}
