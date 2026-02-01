/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:38:17 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/15 15:30:09 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	word_count(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*allocate_word(const char *s, size_t j, char c)
{
	char	*word;
	size_t	len;
	size_t	i;

	len = word_len(&s[j], c);
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[j + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**fill_array(char **arr, const char *s, char c, size_t wc)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (i < wc)
	{
		while (s[j] == c)
			j++;
		arr[i] = allocate_word(s, j, c);
		if (!arr[i])
		{
			k = 0;
			while (k < i)
				free(arr[k++]);
			return (free(arr), NULL);
		}
		j += word_len(&s[j], c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	size_t	wc;

	if (!s)
		return (NULL);
	wc = word_count(s, c);
	arr = malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	return (fill_array(arr, s, c, wc));
}
