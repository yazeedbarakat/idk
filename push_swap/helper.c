/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <yazeed.barakat@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 10:29:05 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/01 15:23:52 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(stack **s)
{
	stack	*temp;
	int	max;

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

int	get_min(stack **s)
{
	stack	*temp;
	int	min;

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

int	get_pos(stack **s, int val)
{
	stack	*temp;
	int	pos;

	temp = *s;
	pos = 0;
	while (temp)
	{
		if (temp->value == val)
			break;
		pos++;
		temp = temp->next;
	}
	return (pos);
}

int	ft_sqrt(int n)
{
	int	x;
	int	y;

	if (n < 0)
		return (0);
	if (n == 0 || n == 1)
		return (n);
	x = n;
	y = 1;
	while (x > y)
	{
		x = (x + y) / 2;
		y = n / x;
	}
	return (x);
}
