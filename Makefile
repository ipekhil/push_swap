NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Proje kaynak dosyaları (manuel yazıldı)
SRCS = assign_index.c \
       find_cost.c \
	   init_stack.c \
	   push_operations.c \
       push_swap.c \
	   rotate_operations.c \
       sort_three.c \
	   swap_operations.c \
       target_of_a.c \
       target_of_b.c \
       utils.c

OBJS = $(SRCS:.c=.o)

# Kütüphane dizinleri ve dosyaları
LIBFT_DIR = libft
PRINTF_DIR = printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

INCLUDES = -I includes -I $(LIBFT_DIR) -I $(PRINTF_DIR)

all: $(NAME)

# Hem libft hem ft_printf derleniyor
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
