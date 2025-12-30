/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 09:07:07 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/30 13:49:35 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

void	ft_strlcpy(char *a, const char *b, size_t l);
size_t	find_next_line(char *line);
size_t	ft_strlen(char *pos);
char	*free_return_pos(char *pos, size_t f);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*allocate_pos(void);
char	*helper(char **pos);

#endif
