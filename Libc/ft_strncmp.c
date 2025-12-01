/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:10:52 by ybarakat          #+#    #+#             */
/*   Updated: 2025/11/25 14:17:35 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *a, const char *b, size_t n)
{
	if (n == 0)
		return (0);
        int	i;

	i = 0;
	while (a[i] == b[i] && i < n && a[i] && b[i])
	{
		i++;
	}
	return (a[i] - b[i]);
}
