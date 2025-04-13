NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = assign_index.c \
       calculate_cost.c \
	   init_stack.c \
	   operations.c \
	   write_operations.c \
	   write_operations2.c \
       push_swap.c \
       target_of_a.c \
       target_of_b.c \
       utils.c \
	   utils2.c \

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I includes -I $(LIBFT_DIR)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)


$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
