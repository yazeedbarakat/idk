/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:09:48 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/29 23:34:10 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

void	ft_strlcpy(char *a, const char *b, size_t l)
{
	size_t	i;

	i = 0;
	while (b[i] && i < l)
	{
		a[i] = b[i];
		i++;
	}
	a[i] = '\0';
}

size_t	find_next_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

size_t	ft_strlen(char *pos)
{
	size_t	i;

	i = 0;
	while (pos[i])
		i++;
	return (i);
}

char	*free_return_pos(char *pos, size_t f)
{
	char	*new_pos;
	size_t	l;

	l = ft_strlen(&pos[f]);
	new_pos = malloc(l + 1);
	ft_strlcpy(new_pos, &pos[f], l);
	free(pos);
	return (new_pos);
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

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*pos;
	char		*line;
	size_t		f;
	size_t		b;

	if (!pos)
	{
		b = read (fd, buff, BUFFER_SIZE);
		buff[b] = '\0';
		pos = malloc (b + 1);
		ft_strlcpy(pos, buff, b);
	}
	while (pos[find_next_line(pos)] != '\n')
	{
		b = read (fd, buff, BUFFER_SIZE);
		if (b == 0)
			break ;
		buff[b] = '\0';
		pos = ft_strjoin(pos, buff);
	}
	if (ft_strlen(pos) == 0)
	{
		free(pos);
		pos = NULL;
		return (NULL);
	}
	f = find_next_line(pos) + 1;
	line = malloc(f + 1);
	ft_strlcpy(line, pos, f);
	pos = free_return_pos(pos, f);
	return (line);
}
