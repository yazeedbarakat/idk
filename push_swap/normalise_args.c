/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabaraka <sabaraka@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:08:44 by sabaraka          #+#    #+#             */
/*   Updated: 2026/02/07 14:08:45 by sabaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		**normalize_args_2(int *argc, char **argv, char **sp, char **newv);

int	has_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		if (s[i++] == ' ')
			return (1);
	return (0);
}

static int	split_count(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	free_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

char	**normalize_args(int *argc, char **argv)
{
	char	**newv;
	char	**sp;
	int		i;
	int		total;

	total = 1;
	i = 1;
	while (i < *argc)
	{
		if (has_space(argv[i]) && !cmp(argv[i]))
		{
			sp = ft_split(argv[i], ' ', 0, 0);
			total += split_count(sp);
			free_split(sp);
		}
		else
			total++;
		i++;
	}
	newv = malloc(sizeof(char *) * (total + 1));
	if (!newv)
		return (NULL);
	return (normalize_args_2(argc, argv, sp, newv));
}

char	**normalize_args_2(int *argc, char **argv, char **sp, char **newv)
{
	int	i;
	int	j;
	int	k;

	newv[0] = argv[0];
	i = 1;
	j = 1;
	while (i < *argc)
	{
		if (has_space(argv[i]) && !cmp(argv[i]))
		{
			sp = ft_split(argv[i], ' ', 0, 0);
			k = 0;
			while (sp[k])
				newv[j++] = sp[k++];
			free(sp);
		}
		else
			newv[j++] = argv[i];
		i++;
	}
	newv[j] = NULL;
	*argc = j;
	return (newv);
}
