# COLORS
END=$'\x1b[0m
BOLD=$'\x1b[1m
UNDER=$'\x1b[4m
REV=$'\x1b[7m
GREY=$'\x1b[30m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m

OS 			:= $(shell uname)
SRCS_DIR	= ./srcs/
HEADER_DIR	= ./includes/

SRCS 		= $(addprefix $(SRCS_DIR),\
				image.c \
				backtracking.c \
				item_collect.c \
				key.c \
				get_next_line.c \
				get_next_line_utils.c \
				read_map.c \
				spawn.c \
				verif_map.c \
				utils.c \
				main.c )

OBJS		= $(SRCS:.c=.o)

CC			= cc
RM			= rm -f
MF 			= Makefile

CFLAGS	= -Wall -Wextra -Werror

# LIBRARY
MLX_DIR 	= ./mlx
MLX_FLAGS	= -lXext -lX11
MLX_PATH	= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -I -g3 -L /usr/X11/lib -L$(HEADER_DIR) -L$(MLX_DIR) -lmlx -I$(MLX_DIR) -lXext -lX11
MAKE_MLX	= make -C $(MLX_DIR)

NAME		= so_long

.c.o:
	@/bin/echo -n .
	@$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $(<:.c=.o)

$(NAME):	$(MF) $(OBJS) libft mlx
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_PATH) $(MLX_FLAGS)  -o $(NAME)
	@echo "\n${GREEN}> so_long was successfuly compiled 🎉${END}"

all: 		$(NAME)

clean:
	@$(RM) $(OBJS)
	@$(MAKE_MLX) clean
	@echo "${YELLOW}> All objects files of so_long have been deleted ❌${END}"

fclean:		clean
	@$(RM) $(NAME)
	@$(MAKE_MLX) clean
	@echo "${YELLOW}> Cleaning of so_long has been done ❌${END}"

re:			fclean all

mlx:
			@$(MAKE_MLX)

.PHONY: all clean fclean re libft mlx