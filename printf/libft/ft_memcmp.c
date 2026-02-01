/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:34:33 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/01 10:34:35 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *a, const void *b, size_t n)
{
	const unsigned char	*sa;
	const unsigned char	*sb;

	sa = (const unsigned char *)a;
	sb = (const unsigned char *)b;
	while (n > 0)
	{
		if (*sa != *sb)
			return (*sa - *sb);
		n--;
		sa++;
		sb++;
	}
	return (0);
}
