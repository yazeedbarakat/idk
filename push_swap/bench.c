/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:52:21 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/08 08:58:51 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_help(int num)
{
	char	*str;

	str = ft_itoa(num);
	write(2, str, len(str));
	free(str);
}

void	print_bench(t_bench *bench)
{
	int	total;

	write(2, "[bench] disorder: ", 19);
	ft_ftoa(bench->disorder);
	write(2, "%\n", 2);
	write(2, "[bench] strategy: ", 19);
	write(2, bench->strategy, len(bench->strategy));
	write(2, "\n", 1);
	total = 0 + bench->sa + bench->sb + bench->ss;
	total += bench->ra + bench->rb + bench->rr;
	total += bench->pa + bench->pb;
	total += bench->rra + bench->rrb + bench->rrb;
	write(2, "[bench] total_ops:  ", 21);
	print_help(total);
	write(2, "\n", 1);
	print_bench_2(bench);
}

void	print_bench_2(t_bench *bench)
{
	write(2, "[bench] sa:  ", 13);
	print_help(bench->sa);
	write(2, "  sb:  ", 7);
	print_help(bench->sb);
	write(2, "  ss:  ", 7);
	print_help(bench->ss);
	write(2, "  pa:  ", 7);
	print_help(bench->pa);
	write(2, "  pb:  ", 7);
	print_help(bench->pb);
	write(2, "\n[bench] ra:  ", 15);
	print_help(bench->ra);
	write(2, "  rb:  ", 7);
	print_help(bench->rb);
	write(2, "  rr:  ", 7);
	print_help(bench->rr);
	write(2, "  rra:  ", 8);
	print_help(bench->rra);
	write(2, "  rrb:  ", 8);
	print_help(bench->rrb);
	write(2, "  rrr:  ", 8);
	print_help(bench->rrr);
	write(2, "\n", 1);
}

t_bench	*make_bench(void)
{
	t_bench	*bench;

	bench = malloc(sizeof(t_bench));
	if (!bench)
		return (NULL);
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->active = 0;
	return (bench);
}
