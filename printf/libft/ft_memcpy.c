/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:31:35 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/15 16:57:56 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *a, const void *b, size_t n)
{
	unsigned char		*sa;
	const unsigned char	*sb;

	if (!a && !b)
		return (a);
	sa = (unsigned char *)a;
	sb = (unsigned char *)b;
	while (n-- > 0)
		*sa++ = *sb++;
	return (a);
}
