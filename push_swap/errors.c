/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabaraka <sabaraka@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:59:44 by sabaraka          #+#    #+#             */
/*   Updated: 2026/02/08 09:24:33 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp(char *str)
{
	if (ft_strncmp(str, "--adaptive", 8) == 0)
		return (1);
	else if (ft_strncmp(str, "--simple", 8) == 0)
		return (1);
	else if (ft_strncmp(str, "--complex", 8) == 0)
		return (1);
	else if (ft_strncmp(str, "--medium", 8) == 0)
		return (1);
	else if (ft_strncmp(str, "--bench", 8) == 0)
		return (1);
	else if (ft_strncmp(str, "--new", 5) == 0)
		return (1);
	return (0);
}

int	num_of_flags(int c, char **arg)
{
	int	one;
	int	two;

	two = 0;
	one = cmp(arg[1]);
	if (c > 2)
	{
		two = cmp(arg[2]);
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
	if (!p)
		return (NULL);
	while (arg[i])
	{
		if (!is_dig(arg[i]))
		{
			free(p);
			return (NULL);
		}
		p[j++] = atoi(arg[i++]);
	}
	return (p);
}

int	check_dup(int c, char **arg, int i, int n)
{
	int	*p;
	int	j;

	p = to_arr(c, arg);
	if (p == NULL)
	{
		free(p);
		return (1);
	}
	while (i < (c - n - 2))
	{
		j = i + 1;
		while (j < (c - n - 1))
		{
			if (p[i] == p[j++])
			{
				free(p);
				return (1);
			}
		}
		i++;
	}
	free(p);
	return (0);
}
