/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:34:16 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/01 10:34:18 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *a, int c, size_t n)
{
	const unsigned char	*b;

	b = (const unsigned char *)a;
	while (n > 0)
	{
		if (*b == (unsigned char)c)
			return ((void *)b);
		n--;
		b++;
	}
	return (NULL);
}
