/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <yazeed.barakat@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:57:04 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/01 15:24:28 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_range(int value, int range_num, int min, int range_size)
{
	int	start;
	int	end;

	start = min + (range_num * range_size);
	end = start + range_size;
	if (value >= start && value < end)
		return (1);
	return (0);
}

void	sort_extend(stack **a, stack **b, int range_num,
		int min, int range_size)
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
			ra(a);
		i++;
	}
}

void	push_back_b(stack **a, stack **b)
{
	int	max;
	int	pos;
	int	size;

	max = get_max(b);
	size = get_size(b);
	pos = get_pos(b, max);
	if (pos > size / 2)
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b);
	}
	else
	{
		while (pos-- > 0)
			rb(b);
	}
	pa(a, b);
}

void	medium_sort(stack **a, stack **b)
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
		ranges = 1;
	range_size = (max - min + 1) / ranges;
	if (range_size < 1)
		range_size = 1;
	i = 0;
	while (i < ranges)
		sort_extend(a, b, i++, min, range_size);
	while (get_size(b) > 0)
		push_back_b(a, b);
}
