/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <yazeed.barakat@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:57:04 by ybarakat          #+#    #+#             */
/*   Updated: 2026/01/28 10:09:24 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_min(stack **a)
{
	stack	*temp;
	int	min;

	temp = *a;
	min = temp->value;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

int	get_max(stack **a)
{
	stack	*temp;
	int	max;

	temp = *a;
	max = temp->value;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

int	in_range(int value, int range_num, int min, range_size)
{
	int	start;
	int	end;

	start = min + (range_num * range_size);
	end = start + range_size;
	if (value >= start && < end)
		return (1);
	return (0);
}

void	sort_extend(stack **a, stack **b, int range_num, int min, int range_size)
{
	int	size;
	int	i;
	int	value;

	size = get_size(a);
	i = 0;
	while (i < size)
	{
		value = (*a)->value;
		if (in_range(value, range_num, min, range_size))
			pb(a, b);
		else
		{
			ra(a);
			i++;
		}
	}
}

void	sort(stack **a, stack **b)
{
	int	min;
	int	max;
	int	ranges;
	int	range_size;
	int	i;

	if (!a || !*a)
		return ;
	min = get_min(a);
	max = get_max(a);
	ranges = ft_sqrt(get_size(*a));
	if (ranges < 1)
		renges = 1;
	range_size = (max - min + 1) / ranges;
	if (range_size < 1)
		range_size = 1;

	i = 0;
	while (i < ranges)
	{
		sort_extend(a, b, i, min, range_size);
		i++;
	}

