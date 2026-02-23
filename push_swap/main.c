/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabaraka <sabaraka@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:08:02 by sabaraka          #+#    #+#             */
/*   Updated: 2026/02/08 09:36:00 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_stack **a, t_stack **b, char *str, t_bench *bench, t_new *new)
{
	if (ft_strncmp(str, "--adaptive", 8) == 0)
		adaptive_sort(a, b, bench);
	else if (ft_strncmp(str, "--simple", 8) == 0)
	{
		bench->strategy = "Simple / O(n2)";
		bench->disorder = disorder(a);
		simple_sort(a, b, bench);
	}
	else if (ft_strncmp(str, "--complex", 8) == 0)
	{
		bench->strategy = "Complex / O(nlogn)";
		bench->disorder = disorder(a);
		complex_sort(a, b, bench);
	}
	else if (ft_strncmp(str, "--medium", 8) == 0)
	{
		bench->strategy = "Medium / O(n√n)";
		bench->disorder = disorder(a);
		medium_sort(a, b, bench);
	}
	else if (ft_strncmp(str, "--bench", 8) == 0)
		bench->active = 1;
	else if (ft_strncmp(str, "--new", 5) == 0)
		new->active = 1;

}

void	sort(int c, char **arg, t_bench *bench, t_new *new)
{
	int		n;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	a = make_stack(c, arg);
	n = num_of_flags(c, arg);
	if (n == 0)
		adaptive_sort(&a, &b, bench);
	else if (n == 1)
	{
		algo(&a, &b, arg[1], bench, new);
		if (bench->active == 1 || new->active == 1)
			adaptive_sort(&a, &b, bench);
	}
	else if (n == 2)
	{
		algo(&a, &b, arg[1], bench, new);
		algo(&a, &b, arg[2], bench, new);
	}
	free_stack(a);
}

int	main(int argc, char **argv)
{
	t_bench	*bench;
	t_new	*new;

	argv = normalize_args(&argc, argv);
	if (!argv)
	{
		free(argv);
		return (0);
	}
	if (check_error(argc, argv) == 0 || check_error(argc, argv) == -1)
	{
		if (check_error(argc, argv) == 0)
			write(2, "Error\n", 6);
		free(argv);
		return (0);
	}
	bench = make_bench();
	new = malloc(sizeof(t_new));
	if (!new)
		return 0;
	new->active = 0;
	if (!bench)
		return (0);
	sort(argc, argv, bench, new);
	if (bench->active == 1)
		print_bench(bench);
	if (new->active == 1)
	{
		new->total = bench->sa + bench->sb + bench->ra + bench->rb + bench->pa + bench->pb;
		new->total = bench->rra + bench->rrb + new->total;
		char	*c = ft_itoa(new->total);
		write (1, "**********\n", 11);
		write (1, c, len(c));
		write (1, "\n**********\n", 12);
		free (c);
	}	
	free(argv);
	free(bench);
	return (0);
}
