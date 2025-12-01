/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:36:17 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/01 10:36:20 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *a)
{
	const char	*sa;
	bool	minus;
	unsigned int	n;

	sa = a;
	while (*sa < '0' || *sa > '9' || *sa == '-')
		sa++;
	if (*sa == '-')
	{
		minus = true;
		sa++;
	}
	n = 0;
	while (*sa >= '0' && *sa <= '9' && *sa != '\0')
	{
		n = n + *sa - '0';
		sa++;
		if (*sa != '\0')
			n = n * 10;
	}
	if (minus)
		n = n * -1;
	return (n);
}
