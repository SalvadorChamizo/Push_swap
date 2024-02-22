NAME = push_swap
ARCHIVE = push_swap
CHECKER = checker
CC = gcc
FLAGS = -Wall -Werror -Wextra 
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

PUSH_SWAP_FILES =	push_swap \
					push_swap_errors \
					push_swap_list \
					push_swap_operators_ps \
					push_swap_operators_r \
					push_swap_operators_rr \
					push_swap_sorting_node \
					push_swap_sorting \
					push_swap_stack \
					push_swap_utils \
					push_swap_print \
					push_swap_while \

CHECKER_FILES =		checker \
					checker_utils \
					checker_list \
					check_operator_ps \
					check_operator_r \

COMMON_FILES =		push_swap_errors \
					push_swap_stack \
					push_swap_utils \

SRCS_DIR = ./src/
CHECKER_SRCS_DIR = ./checker_dir/
PUSH_SWAP_SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(PUSH_SWAP_FILES)))
CHECKER_SRCS = $(addprefix $(CHECKER_SRCS_DIR), $(addsuffix .c, $(CHECKER_FILES))) $(addprefix $(SRCS_DIR), $(addsuffix .c, $(COMMON_FILES)))

OBJS_DIR = ./src/
CHECKER_OBJS_DIR = ./checker_dir/
PUSH_SWAP_OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(PUSH_SWAP_FILES)))
CHECKER_OBJS = $(addprefix $(CHECKER_OBJS_DIR), $(addsuffix .o, $(CHECKER_FILES))) $(addprefix $(OBJS_DIR), $(addsuffix .o, $(COMMON_FILES)))

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(CHECKER_OBJS_DIR)%.o: $(CHECKER_SRCS_DIR)%.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(PUSH_SWAP_OBJS)
	@$(CC) $(FLAGS) $(PUSH_SWAP_OBJS) $(LIBFT) -o $(NAME)

$(CHECKER): $(LIBFT) $(CHECKER_OBJS)
	@$(CC) $(FLAGS) $(CHECKER_OBJS) $(LIBFT) -o $(CHECKER)

$(LIBFT):
	@make -C $(LIBFT_PATH) all

all: $(NAME)

bonus: $(CHECKER)

clean: 
	@rm -f $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME) $(CHECKER)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY = all bonus clean fclean re libft