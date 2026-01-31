/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <yazeed.barakat@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 10:29:05 by ybarakat          #+#    #+#             */
/*   Updated: 2026/01/23 20:14:23 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(stack **a)
{
	double	mistake;
	double	total_pairs;
	stack	*iter;
	stack	*cur;

	if (!a || !(*a) || !(*a)->next)
		return (0);
	mistake = 0;
	total_pairs = 0;
	iter = *a;
	while (iter)
	{
		cur = iter->next;
		while (cur)
		{
			total_pairs++;
			if (iter->value > cur->value)
				mistake++;
			cur = cur->next;
		}
		iter = iter->next;
	}
	return (mistake / total_pairs);
}
