/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:37:59 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/01 10:38:02 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_set(char const *set, char ch)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (ch == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s1;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && in_set(set, s1[start]) == 1)
		start++;
	while (end > start && in_set(set, s1[end - 1]) == 1)
		end--;
	new_s1 = malloc(end - start + 1);
	if (!new_s1)
		return (NULL);
	i = 0;
	while (start < end)
		new_s1[i++] = s1[start++];
	new_s1[i] = '\0';
	return (new_s1);
}
