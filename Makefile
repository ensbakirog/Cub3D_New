NAME	:= cub3D

FLAGS	:= -Wall -Wextra -Werror

LIB_MAC := -Lminilibx_MacOS -lmlx -framework OpenGL -framework AppKit
MLX_MAC := ./minilibx_MacOS

MLX_LIN := ./minilibx_Linux

OS 		:= $(shell uname)

CC		:= gcc
MAKE	:= make
RM		:= rm -rf

SRC		:=	main.c\
			map_scan.c\
			utils.c

LIBFT	= 	Libft/ft_atoi.c\
			Libft/ft_bzero.c\
			Libft/ft_calloc.c\
			Libft/ft_isalnum.c\
			Libft/ft_isalpha.c\
			Libft/ft_isascii.c\
			Libft/ft_isdigit.c\
			Libft/ft_isprint.c\
			Libft/ft_itoa.c\
			Libft/ft_memchr.c\
			Libft/ft_memcmp.c\
			Libft/ft_memcpy.c\
			Libft/ft_memmove.c\
			Libft/ft_memset.c\
			Libft/ft_putchar_fd.c\
			Libft/ft_putendl_fd.c\
			Libft/ft_putnbr_fd.c\
			Libft/ft_putstr_fd.c\
			Libft/ft_split.c\
			Libft/ft_strchr.c\
			Libft/ft_strdup.c\
			Libft/ft_striteri.c\
			Libft/ft_strjoin.c\
			Libft/ft_strlcat.c\
			Libft/ft_strlcpy.c\
			Libft/ft_strlen.c\
			Libft/ft_strmapi.c\
			Libft/ft_strncmp.c\
			Libft/ft_strnstr.c\
			Libft/ft_strrchr.c\
			Libft/ft_strtrim.c\
			Libft/ft_substr.c\
			Libft/ft_tolower.c\
			Libft/ft_toupper.c

GNL     := 	GNL/get_next_line.c\
			GNL/get_next_line_utils.c

OBJ		:= $(SRC:.c=.o)

RED		:= \033[31m
GREEN	:= \033[32m
YELLOW	:= \033[33m
BLUE	:= \033[34m
MAGENTA	:= \033[35m
CYAN	:= \033[36m
RESET	:= \033[0m

CC_MSG_MAC	:= printf "$(CYAN)$(CC)$(RESET) $(YELLOW)$(FLAGS)$(RESET) $(MAGENTA)$(OBJ)$(RESET) $(LIB_MAC) -o $(GREEN)$(NAME)$(RESET)\n"
SUCCESS_MSG	:= @printf "$(GREEN)$(NAME)$(RESET) has been compiled\n"
CLEAN_MSG 	:= printf "$(RED)Object files$(RESET) removed\n"
FCLEAN_MSG	:= printf "Executable $(RED)$(NAME)$(RESET) removed\n"

all: $(NAME)

$(NAME): $(OBJ)
	@if [ "$(OS)" = "Darwin" ]; then \
		$(MAKE) --directory=$(MLX_MAC); \
		$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(GNL) $(LIB_MAC) -o $(NAME); \
		$(CC_MSG_MAC); \
	elif [ "$(OS)" == "Linux" ]; then \
		printf "Merhaba"; \
	fi
	$(SUCCESS_MSG)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@if [ -n "$(wildcard *.o)" ]; then \
		$(RM) $(OBJ); \
		$(CLEAN_MSG); \
	fi
	@make -C $(MLX_MAC) -s clean

fclean: clean
	@if [ -n "$(wildcard $(NAME))" ]; then \
		$(RM) $(NAME); \
		$(FCLEAN_MSG); \
	fi

re: fclean all

.PHONY: all clean fclean re