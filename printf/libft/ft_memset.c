/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:30:43 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/01 10:30:49 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int c, size_t len)
{
	size_t			i;
	unsigned char	*sa;

	sa = (unsigned char *)a;
	i = 0;
	while (i < len)
	{
		sa[i] = (unsigned char)c;
		i++;
	}
	return (a);
}
