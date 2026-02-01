/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:37:29 by ybarakat          #+#    #+#             */
/*   Updated: 2025/12/25 14:01:24 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int		nbr_count_print(int n);
void	print_unbr(unsigned int n);
int		unbr_count_print(unsigned int n);
void	print_hex(unsigned long n, char let);
int		hex_counter(unsigned long n);
int		ft_printf(const char *a, ...);
int		char_percent(char c, va_list args);
int		string_pointer(char c, va_list args);
int		numbers(char c, va_list args);

#endif
