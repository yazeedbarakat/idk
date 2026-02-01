/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:36:28 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/15 16:48:23 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t s)
{
	void	*a;

	if (n != 0 && s > SIZE_MAX / n)
		return (NULL);
	a = malloc(n * s);
	if (!a)
		return (NULL);
	ft_bzero(a, n * s);
	return (a);
}
