/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:53:59 by ylouvel           #+#    #+#             */
/*   Updated: 2024/02/25 23:23:46 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//! PROBLEME: elle appele get_map_value a chaque move ce qui fais crash le programme
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

//TODO: Ajouter le clear des images sur la case : 65307
//TODO: Et changer le switch par des if ou une fonction qui gere les touches appuyer
// Deplace le joueur de 1 case par une case
void	handle_key_input(int keycode, t_data *vars, int *new_x, int *new_y, t_data *essential)
{
	*new_x = vars->player.x;
	*new_y = vars->player.y;
	switch (keycode)
	{
	case 65307:
		exit(1);
		break ;
	case 119:
		*new_y -= 80;
		break ;
	case 97:
		*new_x -= 80;
		break ;
	case 115:
		*new_y += 80;
		break ;
	case 100:
		*new_x += 80;
		break ;
	default:
		break ;
	}
	if (if_valid_move(*new_x, *new_y, essential->files.map)) {
        char map_value = call_get_map_value(*new_x / 80, *new_y / 80, essential->files.map);
        if (map_value == 'C')
            update_map_value(*new_x / 80, *new_y / 80, essential->files.map, '0');

        vars->player.x = *new_x;
        vars->player.y = *new_y;
        mlx_clear_window(vars->mlx, vars->win);
        read_map(vars, essential->files.map);
        display_player(vars);
    }
}

//! PROBLEME elle appelle read_map qui appelle trop de fois des fd
// verifie si il y a un mur et appelle handle_key_input() et display_player pour deplacer le joueur
int	key(int keycode, t_data *vars)
{
	int	new_x;
	int	new_y;
	t_data *essential;

	new_x = vars->player.x;
	new_y = vars->player.y;
	handle_key_input(keycode, vars, &new_x, &new_y, essential);
	if (if_valid_move(new_x, new_y, essential->files.map ))
	{
		vars->player.x = new_x;
		vars->player.y = new_y;
		printf("Touche %c !!!\n", keycode);
		mlx_clear_window(vars->mlx, vars->win);
		read_map(vars, essential->files.map);
		display_player(vars);
	}
	return (0);
}
