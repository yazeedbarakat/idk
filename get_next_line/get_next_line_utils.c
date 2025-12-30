/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:22:40 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/30 13:39:26 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strlcpy(char *a, const char *b, size_t l)
{
	size_t	i;

	if (l == 0)
		return ;
	i = 0;
	while (b[i] && i < l - 1)
	{
		a[i] = b[i];
		i++;
	}
	a[i] = '\0';
}

size_t	ft_strlen(char *pos)
{
	size_t	i;

	i = 0;
	while (pos[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = malloc(s1_len + s2_len + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		newstr[i] = s1[i];
		i++;
	}
	while (i - s1_len < s2_len)
	{
		newstr[i] = s2[i - s1_len];
		i++;
	}
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
