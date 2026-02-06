/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:30:47 by ybarakat          #+#    #+#             */
/*   Updated: 2026/02/06 19:17:47 by ybarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct ben
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	double			disorder;
	char			*strategy;
	int				active;
}					t_bench;
typedef struct r
{
	int start;
	int end;
}					t_range;
t_stack				*make_stack(int c, char **arg);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					check_error(int c, char **arg);
char				*ft_itoa(int n);
void				ft_ftoa(float n);
void				print_help(int num);
int					len(const char *str);
void				print_bench(t_bench *bench);
void				print_bench_2(t_bench *bench);
t_bench				*make_bench(void);
void				index_stack(t_stack *a);
int					bench(char **arg);
int					num_of_flags(int c, char **arg);
int					check_dup(int c, char **arg);
int					get_size(t_stack *s);
int					get_min(t_stack **s);
int					get_max(t_stack **s);
int					get_pos(t_stack **s, int val);
double				disorder(t_stack **a);

void				simple_sort(t_stack **a, t_stack **b, t_bench *bench);
void				medium_sort(t_stack **a, t_stack **b, t_bench *bench);
void				complex_sort(t_stack **a, t_stack **b, t_bench *bench);
void				adaptive_sort(t_stack **a, t_stack **b, t_bench *bench);

void				sa(t_stack **a, t_bench *bench);
void				sb(t_stack **b, t_bench *bench);
void				ss(t_stack **a, t_stack **b, t_bench *bench);
void				pa(t_stack **a, t_stack **b, t_bench *bench);
void				pb(t_stack **a, t_stack **b, t_bench *bench);
void				ra(t_stack **a, t_bench *bench);
void				rb(t_stack **b, t_bench *bench);
void				rr(t_stack **a, t_stack **b, t_bench *bench);
void				rra(t_stack **a, t_bench *bench);
void				rrb(t_stack **b, t_bench *bench);
void				rrr(t_stack **a, t_stack **b, t_bench *bench);
int					str_err(int c, char **arg);

#endif
