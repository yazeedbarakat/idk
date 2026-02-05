/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabaraka <sabaraka@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:10:48 by sabaraka          #+#    #+#             */
/*   Updated: 2026/02/04 00:40:06 by sbarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <stdio.h>

int	out_of_pos(int c, char **arg)
{
	int		i;
	int		j;
	char	*x;

	x = "2147483647";
	i = num_of_flags(c, arg) + 1;
	while (arg[i])
	{
		j = 0;
		if ((len(arg[i]) > 10) && (arg[i][0] != '-'))
			return (1);
		if ((len(arg[i]) == 10) && arg[i][0] != '-')
			while (arg[i][j])
			{
				if (arg[i][j] > x[j])
					return (1);
				j++;
			}
		i++;
	}
	return (0);
}

int	out_of_neg(int c, char **arg)
{
	int		i;
	int		j;
	char	*x;

	x = "-2147483648";
	i = num_of_flags(c, arg) + 1;
	while (arg[i])
	{
		j = 0;
		if (len(arg[i]) > 11)
			return (1);
		if ((len(arg[i]) == 11) && (arg[i][0] == '-'))
			while (arg[i][j])
			{
				if (arg[i][j] > x[j])
					return (1);
				j++;
			}
		i++;
	}
	return (0);
}

int	is_out_of_range(int c, char **arg)
{
	if ((out_of_pos(c, arg) == 1) || (out_of_neg(c, arg) == 1))
		return (1);
	return (0);
}

int	check_error(int c, char **arg)
{
	if (c == 1) // no args
		return (-1);
	// if (c == 2)
	// return (-1);
	if (check_dup(c, arg) == 1) // chec dup
		return (0);
	if (is_out_of_range(c, arg) == 1)
		return (0);
	if (str_err(c, arg) == 1)
		return (0);
	if (c == 2)
		return (-1);
	return (1); // last error (out of range)
}
