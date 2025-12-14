/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:33:50 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/01 10:33:51 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*l;

	l = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			l = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)l);
}
