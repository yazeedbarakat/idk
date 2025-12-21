NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = ft_printf.c hex_number.c unsigned_number.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
