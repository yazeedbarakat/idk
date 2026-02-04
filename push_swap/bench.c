/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:52:21 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/04 20:02:46 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bench(t_bench bench)
{
	int	total;
	
	write (2, "[bench] disorder: ", 21);
	ft_ftoa (bench -> disorder); 
	write (2, "[bench] strategy: ", 21);
	write (2, bench -> strategy,len(bench -> strategy));
	total = 0 + bench -> sa + bench -> sb + bench -> ss;
	total += bench -> ra + bench -> rb + bench -> rr;
	total += bench -> pa + bench -> pb;
	total += bench -> rra + bench -> rrb + bench -> rrb;
	write (2, "[bench] total_ops:  ", 22);
	write (2, ft_itoa(total), len(ft_itoa(total)));
	print_bench_2(bench);
}

void	print_bench_2(t_bench bench)
{
	write (2, "[bench] sa:  ",13);
	write (2, ft_itoa(bench -> sa),len(ft_itoa(bench -> sa)) );
	write (2, "  sb:  ", 7);
	write (2, ft_itoa(bench -> sb), len(ft_itoa(bench -> sb)));
	write (2, "  ss:  ", 7);
	write (2, ft_itoa(bench -> ss), len(ft_itoa(bench -> ss)));
	write (2, "  pa:  ", 7);
	write (2, ft_itoa(bench -> pa), len(ft_itoa(bench -> pa)));
	write (2, "  pb:  ", 7);
	write (2, ft_itoa(bench -> pb), len(ft_itoa(bench -> pb)));
	write (2, "\n[bench] ra:  ", 15);
	write (2, ft_itoa(bench -> ra), len(ft_itoa(bench -> ra)));
        write (2, "  rb:  ", 7);
	write (2, ft_itoa(bench -> rb), len(ft_itoa(bench -> rb)));
        write (2, "  rr:  ", 7);
	write (2, ft_itoa(bench -> rr), len(ft_itoa(bench -> rr)));
        write (2, "  rra:  ", 8);
	write (2, ft_itoa(bench -> rra), len(ft_itoa(bench -> rra)));
        write (2, "  rrb:  ", 8);
	write (2, ft_itoa(bench -> rrb), len(ft_itoa(bench -> rrb)));
        write (2, "  rrr:  ", 8);
	write (2, ft_itoa(bench -> rrr), len(ft_itoa(bench -> rrr)));
}

t_bench	make_bench(void)
{
	t_bench	*bench;

	bench = malloc (sizeof(t_bench));
	if (!bench)
		return (NULL);
	bench = (t_bench *){0};
	return (bench);
}
