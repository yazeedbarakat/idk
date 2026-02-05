#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack_a) // for checking
{
	printf("\nnew stack\n");
	while (stack_a)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
}

void	algo(t_stack **a, t_stack **b, char *str, t_bench *bench)
{
	if (ft_strncmp(str, "--adaptive", 8) == 0)
		adaptive_sort(a, b, bench);
	else if (ft_strncmp(str, "--simple", 8) == 0)
		simple_sort(a, b, bench);
	else if (ft_strncmp(str, "--complex", 8) == 0)
		complex_sort(a, b, bench);
	else if (ft_strncmp(str, "--medium", 8) == 0)
		// change to else = error if there are no flags left
		medium_sort(a, b, bench);
	else if (ft_strncmp(str, "--bench", 8) == 0)
		adaptive_sort(a, b, bench);
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
		adaptive_sort(&a, &b);
	else if (n == 1)
		algo(&a, &b, arg[1]);
	else if (n == 2)
	{
		algo(&a, &b, arg[1]);
		algo(&a, &b, arg[2]);
	}
}
int	main(int argc, char **argv)
{
	t_bench	*bench;
	int		j;

	// stack	*stack_a;
	// stack	*stack_b;
	// stack	**a;
	// stack	**b;
	/*	if (check_error(argc ,argv) == 0 || check_error(argc ,argv) ==
			-1)//first checker for errors
		{
				if (check_error(argc ,argv) == 0)
						write(2,"Error\n",6);
			return (0);
		}*/
	// stack_b = NULL;//at first stack_b is empty
	// stack_a = NULL;
	// a = &stack_a;
	// a = &stack_b;
	/*printf("argc =  %d\n",argc);//print argc
	int i = 0;//from here
	while(i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if(argv[i][j] - '0' >= 0 && argv[i][j] - '0' <= 9)
				printf("%d",argv[i][j] - '0');
			else
				printf("%c",argv[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}//to here print the argv[][]*/
	// stack_a = make_stack(argc, argv);//make stack_a acording to the mehtod
        bench = malloc(sizeof(t_bench));
        if (!bench)
                return (NULL);
        *bench = (t_bench *){0};
	sort(argc, argv, bench);
	return (0);
}
