#include "push_swap.h"

void	algo(t_stack **a, t_stack **b, char *str, t_bench *bench)
{
	if (ft_strncmp(str, "--adaptive", 8) == 0)
		adaptive_sort(a, b, bench);
	else if (ft_strncmp(str, "--simple", 8) == 0)
	{
		bench->strategy = "Simple";
		simple_sort(a, b, bench);
	}
	else if (ft_strncmp(str, "--complex", 8) == 0)
	{
		bench->strategy = "Complex";
		complex_sort(a, b, bench);
	}
	else if (ft_strncmp(str, "--medium", 8) == 0)
	{
		bench->strategy = "Medium";
		medium_sort(a, b, bench);
	}
	else if (ft_strncmp(str, "--bench", 8) == 0)
		bench->active = 1;
}
void	sort(int c, char **arg, t_bench *bench)
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
		algo(&a, &b, arg[1], bench);
		if (bench->active == 1)
			adaptive_sort(&a, &b, bench);
	}
	else if (n == 2)
	{
		algo(&a, &b, arg[1], bench);
		algo(&a, &b, arg[2], bench);
	}
	free(a);
}
int	main(int argc, char **argv)
{
	t_bench	*bench;

	if (check_error(argc ,argv) == 0 || check_error(argc ,argv) ==	-1)
	{
		if (check_error(argc ,argv) == 0)
			write(2,"Error\n",6);
		return (0);
	}
        bench = make_bench();
	if (!bench)
		return (0);
	sort(argc, argv, bench);
	if (bench->active == 1)
		print_bench(bench);
	return (0);
}
