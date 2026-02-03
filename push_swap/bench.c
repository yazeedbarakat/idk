#include "push_swap.h"
#include <stdio.h>

int	bench(char **arg)
{
	if (ft_strncmp(arg[1], "--bench", 8) == 0)
		return (1);//there is a bench
	else if (ft_strncmp(arg[2], "--bench", 8) == 0)
		return (1);//there is a bench
	return (0);
}
void	print_bench(int	*p)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	while(i < 11)
		sum += p[i++];
	write (2, "\ntotal_ops : ", 13);
	write (2, ft_itoa(sum), len(ft_itoa(sum)));
	write (2, "\nsa :  ", 7);
	write (2, ft_itoa(p[2]), len(ft_itoa(p[2])));
	write (2, "sb :  ", 6);
	write (2, ft_itoa(p[3]), len(ft_itoa(p[3])));
	write (2, "ss :  ", 6);
	write (2, ft_itoa(p[4]), len(ft_itoa(p[4])));
	write (2, "pa :  ", 6);
	write (2, ft_itoa(p[0]), len(ft_itoa(p[0])));
	write (2, "pb :  ", 6);
	write (2, ft_itoa(p[1]), len(ft_itoa(p[1])));
	write (2, "\nra :  ", 7);
	write (2, ft_itoa(p[5]), len(ft_itoa(p[5])));
	write (2, "rb :  ", 6);
	write (2, ft_itoa(p[6]), len(ft_itoa(p[6])));
	write (2, "rr :  ", 6);
	write (2, ft_itoa(p[7]), len(ft_itoa(p[7])));
	write (2, "rra :  ", 7);
	write (2, ft_itoa(p[8]), len(ft_itoa(p[8])));
	write (2, "rrb :  ", 7);
	write (2, ft_itoa(p[9]), len(ft_itoa(p[9])));
	write (2, "rrr :  ", 7);
	write (2, ft_itoa(p[10]), len(ft_itoa(p[10])));
}

void	bench_stat_s(p_list **a, int bench, int op,int *p){//static arr[11],    p_list b
	if (op == 5)
	{
		ra (a, bench);
		(p[5])++;
	}
	else if (op == 8)
	{
		rra (a, bench);
		(p[8])++;
	}
}

int	*bench_stat_f(p_list **a, p_list **b, int bench, int op, int end)
{
	static int	arr[11] = {0};

	//arr[11] = {0};
	if (op == 0)
	{
		pa(a, b, bench);
		arr[0]++;
	}
	else if (op == 1)
	{
		pb(a, b, bench);
		arr[1]++;
	}
	else if (op  == 2)
	{
		sa (a, bench);
		arr[2]++;
	}
	else
		bench_stat_s(a, bench, op, arr);
	if (end == 1)
		return (arr);
	return (NULL);
}
