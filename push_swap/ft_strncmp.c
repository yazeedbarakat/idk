/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarakat <sbarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:31:32 by sbarakat          #+#    #+#             */
/*   Updated: 2026/01/28 11:43:03 by sbarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t  i;

	i = 0;
	while (i < n)
        {
                if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
                        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
                i++;
        }
        return (0);
}
