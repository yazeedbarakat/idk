/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:19:12 by ybarakat          #+#    #+#             */
/*   Updated: 2026/01/22 16:36:47 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ra(p_list **a)
{
	p_list	*top;
	p_list	*last;

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

void	rb(p_list **b)
{
	p_list  *top;
	p_list  *last;
	
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

void	rr(p_list **a, p_list **b)
{
	ra(a);
	rb(b);
}
