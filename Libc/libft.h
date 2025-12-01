#ifndef LIBFT_H
# define LIBFT_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int			ft_isalpha(int a);
int			ft_isdigit(int a);
int			ft_isalnum(int a);
int			ft_isascii(int a);
int			ft_isprint(int a);
size_t			ft_strlen(const char *a);
void			*ft_memset(void *a, int c, size_t n);
void			ft_bzero(void *a, size_t n);
void			*ft_memcpy(void *a, void *b, size_t n);
void			*ft_memmove(void *a, void *b, size_t n);
typedef struct		s_list
{
	coid		*content;
	struct s_list	*next;
}			t_list;
#endif
