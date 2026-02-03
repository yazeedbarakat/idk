/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarakat <sbarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:31:26 by sbarakat          #+#    #+#             */
/*   Updated: 2026/02/03 06:00:24 by sbarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	pown(int power)
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

stack	*make_stack(int c, char **arg)
{
	stack	*p;
	stack	*l;
	stack	*top;
	int	i;

	i = num_of_flags(c, arg) + 1;//we skip file name and first el
	p = (stack *)malloc(sizeof (stack));//here we can add a top pointer
	top = p;
	if (!p)
		return (NULL);//
	p -> value = atoi(arg[i++]);
	p -> prev = NULL;
	p -> next = NULL;
	while (i < c)
	{
		l = (stack *)malloc(sizeof (stack));
		if (!l)
			return (NULL);//
		l -> value = atoi(arg[i++]);
		p -> next = l;
		l -> prev = p;
		p = l;
	}
	l -> next = NULL;
	return (top);
}
