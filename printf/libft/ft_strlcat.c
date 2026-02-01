/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:32:19 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/01 10:32:21 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *a, const char *b, size_t n)
{
	size_t	ac;
	size_t	bc;
	size_t	i;
	size_t	j;

	ac = 0;
	while (a[ac] && ac < n)
		ac++;
	bc = 0;
	while (b[bc])
		bc++;
	i = ac;
	j = 0;
	if (ac == n)
		return (n + bc);
	while (b[j] && i < n - 1)
	{
		a[i++] = b[j++];
	}
	a[i] = '\0';
	return (ac + bc);
}
