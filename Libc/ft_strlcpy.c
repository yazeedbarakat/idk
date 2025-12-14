/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:32:08 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/01 10:32:10 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *a, const char *b, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (b[i] && i < n - 1)
		{
			a[i] = b[i];
			i++;
		}
		a[i] = '\0';
	}
	return (ft_strlen(b));
}
