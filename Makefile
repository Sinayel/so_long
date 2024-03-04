CC = 			cc
CFLAGS = 		-Wall -Wextra -Werror -L/home/ylouvel/sooooooooooo_long/mlx/ -lmlx -lXext -lX11

RM = 			rm -f

NAME = 			so_long.o

SRCS_DIR	= ./srcs/

SO_LONG_SRC = $(addprefix $(SRCS_DIR),\
				backtracking.c \
				backtracking_verif.c \
				get_next_line_utils.c \
				get_next_line.c image.c \
				item_collect.c \
				key.c \
				main.c \
				read_map.c \
				spawn.c \
				utils.c \
				verif_map.c )

all : 		so_long

so_long :
				${CC} ${SO_LONG_SRC} ${CFLAGS} -o ${NAME}

map :		so_long
				./${NAME} map/map2.ber

map1 :		so_long
				./${NAME} maps/map1.ber

map2 :		so_long
				./${NAME} maps/map2.ber
				
re : 		fclean all

clean:
				$(RM) so_long.out

fclean: 	clean
				$(RM) $(NAME)

.PHONY: 	fclean clean re all

# cc -Wall -Wextra -Werror convert_map.c get_next_line.c get_next_line_utils.c movements.c 
# ft_check.c so_long_utils.c so_long_mvmt.c so_long_len_utils.c so_long_check_utils.c so_long.c 
# -L/home/judenis/sgoinfre/judenis/42projects/so_long/minilibx/ -lmlx -lXext -lX11 -o a.out