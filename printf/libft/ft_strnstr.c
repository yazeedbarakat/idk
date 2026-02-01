/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:35:57 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/01 10:36:00 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *a, const char *b, size_t n)
{
	size_t	i;
	size_t	j;

	if (*b == '\0')
		return ((char *)a);
	i = 0;
	while (a[i] && i < n)
	{
		j = 0;
		while (a[i + j] && b[j] && (i + j) < n && a[i + j] == b[j])
			j++;
		if (b[j] == '\0')
			return ((char *)&a[i]);
		i++;
	}
	return (NULL);
}
