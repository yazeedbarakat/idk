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

void	*ft_memmove(void *a, const void *b, size_t n)
{
	unsigned char		*as;
	const unsigned char	*bs;

	as = (unsigned char *)a;
	bs = (const unsigned char *)b;
	if (a > b)
	{
		while (n > 0)
		{
			n--;
			as[n] = bs[n];
		}
	}
	else
		ft_memcpy(as, bs, n);
	return (as);
}
