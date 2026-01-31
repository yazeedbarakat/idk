/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:19:12 by ybarakat          #+#    #+#             */
/*   Updated: 2026/01/23 20:09:57 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}

void	rr(stack **a, stack **b)
{
	ra(a);
	rb(b);
}
