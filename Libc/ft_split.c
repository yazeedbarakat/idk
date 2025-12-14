/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:38:17 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/01 10:38:19 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

char	**set_mem(char const *s, char c)
{
	char	**a;
	size_t	i;
	size_t	j;
	size_t	wc;

	wc = word_count(s, c);
	a = malloc(sizeof(char *) * (wc + 1));
	if (!a)
		return (NULL);
	i = 0;
	j = 0;
	while (i < wc)
	{
		while (s[j] == c)
			j++;
		a[i] = malloc(word_len(&s[j], c) + 1);
		if (!a[i])
			return (NULL);
		j = j + word_len(&s[j], c);
		i++;
	}
	a[i] = NULL;
	return (a);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	wc;

	wc = word_count(s, c);
	a = set_mem(s, c);
	i = 0;
	j = 0;
	while (s[i] != '\0' && j < wc)
	{
		while (s[i] == c)
			i++;
		k = 0;
		while (s[i] != '\0' && s[i] != c)
		{
			a[j][k] = s[i];
			i++;
			k++;
		}
		a[j][k] = '\0';
		j++;
	}
	return (a);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void    print_split(char **arr)
{
    int i = 0;

    if (!arr)
    {
        printf("NULL returned\n");
        return;
    }
    while (arr[i])
    {
        printf("  [%d] \"%s\"\n", i, arr[i]);
        i++;
    }
}

void    free_split(char **arr)
{
    int i = 0;
    if (!arr)
        return;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void    test(char *str, char sep)
{
    printf("Input: \"%s\" | sep = '%c'\n", str, sep);
    char **res = ft_split(str, sep);
    print_split(res);
    free_split(res);
    printf("-----------------------------\n");
}

int main(void)
{
    test("Hello--world--libft", '-');
    test("----42----school----", '-');
    test("no_delimiters", '-');
    test("", '-');
    test("--a--b--c--", '-');
    test("     split this     text   ", ' ');

    return (0);
}
*/
