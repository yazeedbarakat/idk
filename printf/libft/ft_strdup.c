/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:36:39 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/01 10:36:41 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *a)
{
	char	*b;
	size_t	l;
	size_t	i;

	l = ft_strlen(a);
	b = malloc(l + 1);
	if (!b)
		return (NULL);
	i = 0;
	while (i < l)
	{
		b[i] = a[i];
		i++;
	}
	b[i] = '\0';
	return (b);
}
