/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:53:59 by ylouvel           #+#    #+#             */
/*   Updated: 2024/03/04 17:04:43 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// verifier si le deplacement et possible
int	if_valid_move(int new_x, int new_y, char *map)
{
	int		map_x;
	int		map_y;
	char	map_value;
	int		nb_line;

	nb_line = ft_strlen_sous_coke(map);
	map_x = new_x / 80;
	map_y = new_y / 80;
	if (map_x < 0 || map_x >= nb_line || map_y < 0 || map_y >= nb_line)
		return (0);
	map_value = call_get_map_value(map_x, map_y, map);
	if (map_value == '1')
		return (0);
	return (1);
}

// TODO: Ajouter le clear des images sur la case : 65307
// TODO: Et changer le switch
// Deplace le joueur de 1 case par une case
void	handle_key_input(int keycode, t_data *vars, int *new_x, int *new_y)
{
	char	map_value;

	*new_x = vars->player.x;
	*new_y = vars->player.y;
	if (keycode == 119)
		*new_y -= 80;
	if (keycode == 97)
		*new_x -= 80;
	if (keycode == 115)
		*new_y += 80;
	if (keycode == 100)
		*new_x += 80;
	if (keycode == 65307)
		destroy_images(vars);
	if (if_valid_move(*new_x, *new_y, vars->map))
	{
		map_value = call_get_map_value(*new_x / 80, *new_y / 80,
				vars->map);
		if (map_value == 'C')
			update_map_value(*new_x / 80, *new_y / 80, vars->map,
				'0');
		if (number_of_c(vars->map) == 0 && map_value == 'E')
			exit(1);
		vars->player.x = *new_x;
		vars->player.y = *new_y;
		mlx_clear_window(vars->mlx, vars->win);
		read_map(vars, vars->map);
		display_player(vars);
	}
}

//! PROBLEME elle appelle read_map qui appelle trop de fois des fd
// verifie si il y a un mur et appelle handle_key_input() et display_player pour deplacer le joueur
int	key(int keycode, t_data *vars)
{
	int		new_x;
	int		new_y; 

	new_x = vars->player.x;
	new_y = vars->player.y;
	handle_key_input(keycode, vars, &new_x, &new_y);
	if (if_valid_move(new_x, new_y, vars->map))
	{
		vars->player.x = new_x;
		vars->player.y = new_y;
		printf("Touche %c !!!\n", keycode);
		mlx_clear_window(vars->mlx, vars->win);
		read_map(vars, vars->map);
		display_player(vars);
	}
	return (0);
}
