BOLD=\033[1m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
SET=\033[0m

CH_NAME			=	checker
# PS_NAME			=	push_swap

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g

INC_DIR			=	./include
SRCS_DIR		=	./srcs
OBJS_DIR		=	./objs

# CHECKER
CH_SRCS			=	checker.c \
					pile.c

CH_OBJS			=	$(addprefix $(OBJS_DIR)/, $(CH_SRCS:.c=.o))

# PUSH_SWAP
# PS_SRCS			=
# PS_OBJS			=	$(addprefix $(OBJS_DIR)/, $(PS_SRCS:.c=.o))

# LIBFT
LIBFT_DIR		=	./libft
LIBFT_INC		=	-I $(LIBFT_DIR)
LIBFT_LNK		=	-L $(LIBFT_DIR) -lft
LIBFT_LIB		=	$(addprefix $(LIBFT_DIR)/, libft.a)

all				:	objs $(LIBFT_LIB) $(CH_NAME)

objs			:
					@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o	:	$(SRCS_DIR)/%.c
					@$(CC) $(CFLAGS) $(LIBFT_INC) -I $(INC_DIR) -c $< -o $@

$(LIBFT_LIB)	:
					@echo "$(YELLOW)Compiling libft...$(SET)"
					@make -C $(LIBFT_DIR)
					@echo "$(GREEN)Libft is compiled !$(SET)"

$(CH_NAME)		:	$(CH_OBJS)
					@echo "$(YELLOW)Compiling checker...$(SET)"
					@$(CC) $(CH_OBJS) $(LIBFT_LNK) -lm -o $(CH_NAME)
					@echo "$(GREEN)Checker is compiled !$(SET)"

# $(CH_NAME)		:	$(PS_OBJS)
# 					@echo "$(YELLOW)Compiling push_swap...$(SET)"
# 					$(CC) $(PS_OBJS) $(LIBFT_LNK) -lm -o $(PS_NAME)
# 					@echo "$(GREEN)Push_swap is compiled !$(SET)"

clean			:
					@rm -rf $(OBJS_DIR)
					@make -C $(LIBFT_DIR) clean

fclean			:	clean
					@rm -f $(CH_NAME)
					@make -C $(LIBFT_DIR) fclean

re				:	fclean all
