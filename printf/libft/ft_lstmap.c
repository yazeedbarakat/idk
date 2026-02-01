/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:31:50 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/15 15:31:52 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	if (lst && f && del)
	{
		while (lst != NULL)
		{
			b = ft_lstnew(f(lst->content));
			if (!b)
			{
				ft_lstclear(&a, del);
				return (NULL);
			}
			ft_lstadd_back(&a, b);
			lst = lst->next;
		}
	}
	return (a);
}
