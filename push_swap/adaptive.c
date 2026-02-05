/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:20:51 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/05 12:13:38 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	double	dis;

	dis = disorder(a);
	bench->disorder = dis;
	if (dis < 0.2)
		simple_sort(a, b, bench);
	else if (dis >= 0.2 && dis < 0.5)
		medium_sort(a, b, bench);
	else
		complex_sort(a, b, bench);
}
