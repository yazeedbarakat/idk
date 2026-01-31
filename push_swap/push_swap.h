/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:30:47 by ybarakat          #+#    #+#             */
/*   Updated: 2026/01/23 20:07:02 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
#include <stdlib.h>

typedef struct s_list
{
	int		value;
	struct s_list	*prev;
	struct s_list	*next;
}	stack;

void    sa(stack **a);
void	sb(stack **b);
void    ss(stack **a, stack **b);
void    pa(stack **a, stack **b);
void    pb(stack **a, stack **b);
void    ra(stack **a);
void    rb(stack **b);
void    rr(stack **a, stack **b);
void    rra(stack **a);
void    rrb(stack **b);
void    rrr(stack **a, stack **b);

#endif
