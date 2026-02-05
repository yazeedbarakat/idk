/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <yazeed.barakat@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 10:29:05 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/05 11:50:49 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack **s)
{
	t_stack	*temp;
	int		max;

	temp = *s;
	max = temp->value;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

int	get_min(t_stack **s)
{
	t_stack	*temp;
	int		min;

	temp = *s;
	min = temp->value;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

int	get_pos(t_stack **s, int val)
{
	t_stack	*temp;
	int		pos;

	temp = *s;
	pos = 0;
	while (temp)
	{
		if (temp->value == val)
			break ;
		pos++;
		temp = temp->next;
	}
	return (pos);
}
