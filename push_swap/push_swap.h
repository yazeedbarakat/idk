/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:30:47 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/03 18:48:08 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int		value;
	struct s_stack	*prev;
	struct s_stack	*next;
}	stack;

stack	*make_stack(int c, char **arg);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     check_error(int c, char **arg);
char    *ft_itoa(int n);
int     len(const char *str);
int    *bench_stat_f(stack **a, stack **b, int bench, int op, int end);
void	print_bench(int *p);
int	bench(char **arg);
int	num_of_flags(int c, char **arg);
int	check_dup(int c, char **arg);
int             get_size(stack *s);
int             get_min(stack **s);
int             get_max(stack **s);
int             get_pos(stack **s, int val);
double  disorder(stack **a);
int             ft_sqrt(int n);

void    simple_sort(stack **a, stack **b);
void    medium_sort(stack **a, stack **b);
void    complex_sort(stack **a, stack **b);
void    adaptive_sort(stack **a, stack **b);

void    sort_extend(stack **a, stack **b, int start, int end);
void    push_back_b(stack **a, stack **b);

void    sa(stack **a);
void    sb(stack **b);
void    ss(stack **a, stack **b);
void    pa(stack **a, stack **b);
void    pb(stack **a, stack **b);
void    ra(stack **a);
void    rb(stack **b);
void    rr(stack **a, stack **b);
void    rra(stack **a);
void    rrb(stack **b);
void    rrr(stack **a, stack **b);

#endif
