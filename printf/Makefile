NAME = jinja
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): ft_printf.c $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) ft_printf.c -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
