/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabaraka <sabaraka@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:10:09 by sabaraka          #+#    #+#             */
/*   Updated: 2026/02/07 14:10:12 by sabaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pown(int power)
{
	int	sum;

	sum = 1;
	while (power > 0)
	{
		sum *= 10;
		power--;
	}
	return (sum);
}

int	len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	atoi(const char *str)
{
	int	neg;
	int	sum;
	int	i;
	int	l;

	l = len(str);
	neg = 1;
	sum = 0;
	i = 0;
	if (str[0] == '-')
	{
		neg = -1;
		i++;
		l--;
	}
	while (str[i])
	{
		sum += (str[i++] - '0') * pown(--l);
	}
	return (neg * sum);
}

t_stack	*ms_help(t_stack *p, t_stack *l)
{
	l->index = -1;
	p->next = l;
	l->prev = p;
	return (l);
}

t_stack	*make_stack(int c, char **arg)
{
	t_stack	*p;
	t_stack	*l;
	t_stack	*top;
	int		i;

	i = num_of_flags(c, arg) + 1;
	p = (t_stack *)malloc(sizeof(t_stack));
	top = p;
	if (!p)
		return (NULL);
	p->value = atoi(arg[i++]);
	p->index = -1;
	p->prev = NULL;
	p->next = NULL;
	while (i < c)
	{
		l = (t_stack *)malloc(sizeof(t_stack));
		if (!l)
			return (NULL);
		l->value = atoi(arg[i++]);
		p = ms_help(p, l);
	}
	p->next = NULL;
	return (top);
}
