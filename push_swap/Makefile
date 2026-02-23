NAME = push_swap

CC = cc
CFLAGS = -Werror -Wextra -Wall

SRCS = \
       adaptive.c\
       check_errors.c\
       complex_sort.c\
       errors.c\
       ft_strncmp.c\
       main.c\
       medium_sort.c\
       rra_rrb_rrr.c\
       simple_sort.c\
       disorder.c\
       ft_itoa.c\
       helper.c\
       make_stack.c\
       pa_pb.c\
       ra_rb_rr.c\
       sa_sb_ss.c\
       str_err.c\
       bench.c\
       split.c\
       normalise_args.c\
       free_stack.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re	
