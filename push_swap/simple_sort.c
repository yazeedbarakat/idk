/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:10:32 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/04 18:12:51 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(stack **a, stack **b, t_bench *bench)
{
	int	min;
	int	pos;
	int	size;

	size = get_size(*a);
	while (size > 1)
	{
		min = get_min(a);
		pos = get_pos(a, min);
		if (pos == 1)
			sa(a, bench);
		else if (pos <= size / 2)
			while ((*a)->value != min)
				ra(a, bench);
		else
			while ((*a)->value != min)
				rra(a, bench);
		pb(a, b, bench);
		size--;
	}
	while (*b)
		pa(a, b, bench);
}
