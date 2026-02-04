#include "push_swap.h"
int	is_str(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	str_err(int c, char **arg)
{
	int	i;
	int	j;

	i = num_of_flags(c, arg) + 1;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (is_str(arg[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
