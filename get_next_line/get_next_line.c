/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:09:48 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/30 13:44:55 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	find_next_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

char	*free_return_pos(char *pos, size_t f)
{
	char	*new_pos;
	size_t	l;

	l = ft_strlen(&pos[f]);
	new_pos = malloc(l + 1);
	if (!new_pos)
		return (NULL);
	ft_strlcpy(new_pos, &pos[f], l + 1);
	free(pos);
	return (new_pos);
}

char	*allocate_pos(void)
{
	char	*pos;

	pos = malloc(1);
	if (!pos)
		return (NULL);
	pos[0] = '\0';
	return (pos);
}

char	*helper(char **pos)
{
	size_t	len;
	char	*line;

	len = find_next_line(*pos);
	if ((*pos)[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *pos, len + 1);
	*pos = free_return_pos(*pos, len);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*pos;
	int		b;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!pos)
		pos = allocate_pos();
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!ft_strchr(pos, '\n') && (b = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[b] = '\0';
		pos = ft_strjoin(pos, buff);
	}
	free(buff);
	if (b == -1 || ft_strlen(pos) == 0)
	{
		free(pos);
		return (pos = NULL);
	}
	return (helper(&pos));
}
