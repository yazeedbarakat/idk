/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:30:47 by ybarakat          #+#    #+#             */
/*   Updated: 2026/01/22 16:37:32 by ybarakat         ###   ########.fr       */
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
}	p_list;

void    sa(p_list **a);
void	sb(p_list **b);
void    ss(p_list **a, p_list **b);
void    pa(p_list **a, p_list **b);
void    pb(p_list **a, p_list **b);
void    ra(p_list **a);
void    rb(p_list **b);
void    rr(p_list **a, p_list **b);
void    rra(p_list **a);
void    rrb(p_list **b);
void    rrr(p_list **a, p_list **b);

#endif
