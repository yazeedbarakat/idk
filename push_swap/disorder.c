/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:15:26 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/03 12:49:48 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	disorder(stack **a)
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
