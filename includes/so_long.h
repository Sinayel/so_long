/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:07:30 by ylouvel           #+#    #+#             */
/*   Updated: 2024/03/04 16:38:47 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 1
#include "../mlx/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#define SIZE 100
#define MAX_MAP_SIZE 13

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_sortie 
{
	void 		*img_sortie;
}				t_sortie;

typedef struct
{
    int x;
    int y;
    off_t start_of_line;
}			PositionInfo;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img_player;
	void		*img_map;
	void		*img_background;
	void		*img_item;
	int			found_c;
	int			found_e;
	int			found_p;
	int			*mvmt;
	int			width;
	int			height;
	t_player	player;
	t_sortie	file_for_exit;
	char 		*map;
}				t_data;

//* --------------------------------MAP-------------------------------- //
void			read_map(t_data *vars, char *map);
void			read_and_display_map(int fd, t_data *vars, char *map);
void			display_player(t_data *vars);
void			update_map_value(int x, int y, char *map, char new_value);
int				number_of_c(char *map);
int				number_of_e(char *map);


//* --------------------------------SPAWN_PLAYER-------------------------------- //
void			read_for_player(t_data *vars, int fd, char *map);
void			for_player(t_data *vars, char *map);


//* --------------------------------GET_VALUE-------------------------------- //
int				largeur_map(t_data *vars);
int				ft_strlen_sous_coke(char *map);
char			get_map_value(int x, int y,	int fd, int nb_line);
char			call_get_map_value(int x, int y, char *map);
void			update_coordinates(int *j, int *x, int *y, int nb_line);
void 			for_update_coordinates(int *j, int *x, int *y, char *map);


//* --------------------------------MOVE-------------------------------- //
int				key(int keycode, t_data *vars);
int				if_valid_move(int new_x, int new_y, char *map);
void			handle_key_input(int keycode, t_data *vars, int *new_x, int *new_y);


//* --------------------------------VERIF_MAP-------------------------------- //
int     		return_yes_or_no(char *buffer, char *buf);
int    			for_verif_exterior(char *map, t_data *vars);
int     		verif_exterior(t_data *vars, int nb_line, int fd);
int     		return_yes_or_no_for_side_right(t_data *vars, char *side);
int				compteur_line(char *side);
int				compteur_line_last(char *side);
void			stockstrdup_size_of_buffer(char *buffer);


//* ---------------------------VERIF_MAP_INTERIOR-------------------------------- //
int				verif_map_for_c(char map[SIZE][SIZE], int visited[SIZE][SIZE], int x,
		int y);
int				verif_map_for_p(char map[SIZE][SIZE], int visited[SIZE][SIZE], int x,
		int y);
int				verif_map_for_e(char map[SIZE][SIZE], int visited[SIZE][SIZE], int x,
		int y);
int				open_file_read(char *filename, char map[][SIZE]);
int 		for_backtracking(char *Rmap);
int			backtracking(char *Rmap, int result_c, int result_e, int result_p);


//* --------------------------------ITEM-------------------------------- //
int				open_map_file(char *map);
int				calculate_line_length(char *map);
void			close_map_file(int fd);
void			back_to_position(int fd, off_t position);
void			write_new_value(int fd, char new_value);
void 			update_map_value(int x, int y, char *map, char new_value);
void			update_map(int fd, off_t position, char new_value);


//! --------------------------------IMAGE-------------------------------- //
void			destroy_images(t_data *vars);
void			display_map_element(char buffer, int x, int y, t_data *vars);
void			push_img(t_data *vars, int one_or_zero);
void			load_images(t_data *vars);


//TODO --------------------------------UTILS-------------------------------- //
int				cross_close(t_data *vars);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
// int 			count_open_fds();


//? --------------------------------GET_NEXT_LINE-------------------------------- //
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *string, int searchedChar );
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*ft_free(char *buffer, char *buf);
char	*ft_next(char *buffer);
char	*ft_line(char *buffer);
char	*read_file(int fd, char *res);
