/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:31:46 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/01 10:31:49 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *a, void *b, size_t n)
{
	unsigned char	*t;

	t = malloc(n);
	ft_memcpy(t, b, n);
	ft_memcpy(a, t, n);
	free(t);
	return (a);
}
