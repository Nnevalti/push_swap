NAME			= 	libft.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

SRCS_DIR		=	./srcs
OBJS_DIR		=	./objs
INC_DIR			=	./include

SRCS			=	ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memccpy.c \
					ft_memmove.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_strlen.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_isspace.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strcmp.c \
					ft_strncmp.c \
					ft_strcpy.c \
					ft_strncpy.c \
					ft_strlcpy.c \
					ft_strcat.c \
					ft_strncat.c \
					ft_strlcat.c \
					ft_strstr.c \
					ft_strnstr.c \
					ft_atoi.c \
					ft_calloc.c \
					ft_strdup.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_strnjoin.c \
					ft_strtrim.c \
					ft_split.c \
					ft_tablen.c \
					ft_itoa.c \
					ft_strmapi.c \
					ft_putchar.c \
					ft_putstr.c \
					ft_putendl.c \
					ft_putnbr.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_lstnew_bonus.c \
					ft_lstadd_front_bonus.c \
					ft_lstsize_bonus.c \
					ft_lstlast_bonus.c \
					ft_lstadd_back_bonus.c \
					ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstmap_bonus.c \
					get_next_line.c

OBJS			=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all				:	objs $(NAME)

objs			:
					@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o	:	$(SRCS_DIR)/%.c
					@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME)			:	$(OBJS)
					@ar rc $(NAME) $(OBJS)

clean			:
					@rm -rf objs

fclean			:	clean
					@rm -f $(NAME)


re				: 	fclean all
