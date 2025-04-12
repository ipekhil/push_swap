NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

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
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I includes -I $(LIBFT_DIR)

all: $(NAME)

#  libft derleniyor
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)


$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
