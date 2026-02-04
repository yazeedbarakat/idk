/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:52:21 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/04 17:18:27 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	make_bench(void)
{
	t_bench	*bench;

	bench = malloc (sizeof(t_bench));
	if (!bench)
		return (NULL);
	bench = (t_bench *){0};
	return (bench);
}
