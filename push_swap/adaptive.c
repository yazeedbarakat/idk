/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:20:51 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/01 14:34:45 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	adaptive_sort(stack **a, stack **b)
{
	double	dis;

	dis = disorder(a);
	if (dis < 0.2)
		simple_sort(a, b);
	else if (dis >= 0.2 && dis < 0.5)
		medium_sort(a, b);
	else
		complex_sort(a, b);
}
