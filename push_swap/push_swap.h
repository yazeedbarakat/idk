/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <yazeed.barakat@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:30:47 by ybarakat          #+#    #+#             */
/*   Updated: 2026/01/22 13:46:05 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>

typedef struct s_list
{
	int		value;
	struct s_list	*prev;
	struct s_list	*next;
}	p_list;

void    s_stack(p_list **stack);
void    ss_stack(p_list **a, p_list **b);
