/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <yazeed.barakat@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:57:40 by ybarakat          #+#    #+#             */
/*   Updated: 2026/01/22 13:18:24 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	p_stack(p_list	*first, p_list *second)
{
	p_list	*save;
	p_list	*new_h;
	p_lst	*temp;

	new_h = malloc(sizeof(p_list));
	if (!new_h)
		return (NULL);
	if (second != NULL)
	{
		save = first;
		new_h->next = save;;
		save->prev = new_h;
		first = new_h;
		new_h->value = second->value;
		temp = second;
		second = second->next;
		free(temp);
	}


