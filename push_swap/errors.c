/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabaraka <sabaraka@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:59:44 by sabaraka          #+#    #+#             */
/*   Updated: 2026/02/03 06:08:50 by sbarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stddef.h>
#include <stdio.h>

int	cmp(char *str)
{
	if (ft_strncmp(str, "--adaptive", 8) == 0)
		return (1);
	else if (ft_strncmp(str, "--simple", 8) == 0)
		return (1);
	else if (ft_strncmp(str, "--complex", 8) == 0)
		return (1);
	else if (ft_strncmp(str, "--medium", 8) == 0)
		// change to else = error if there are no flags left
		return (1);
	else if (ft_strncmp(str, "--bench", 8) == 0)
		return (1);
	return (0);
}

int	num_of_flags(int c, char **arg)
{
	int	one;
	int	two;

	two = 0; // uninitalized error
	one = cmp(arg[1]);
	if (c > 2)
	{
		two = cmp(arg[2]); // if c ==2 segfault
		if (one && two)
			return (2);
		if (one)
			return (1);
	}
	return (0);
}

int	is_dig(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	*to_arr(int c, char **arg)
{
	int	i;
	int	j;
	int	n;
	int	*p;

	n = num_of_flags(c, arg);
	i = 1 + n;
	j = 0;
	p = (int *)malloc(sizeof(int) * (c - 1 - n));
	while (arg[i])
	{
		if (!is_dig(arg[i]))
			return (NULL);
		p[j++] = atoi(arg[i++]);
	}
	return (p);
}

int	check_dup(int c, char **arg)
{
	int	*p;
	int	i;
	int	j;
	int	n;

	i = 0;
	p = to_arr(c, arg);
	if (p == NULL)
		return (1);
	n = num_of_flags(c, arg);
	while (i < (c - n - 2)) // so it doesnt compare the last el with it self(-2)
	{
		j = i + 1; // segfaualt when c == 2
		while (j < (c - n - 1))
		{
			if (p[i] == p[j])
			{
				free(p);
				return (1);
			}
			j++;
		}
		i++;
	}
	free(p);
	return (0);
}
