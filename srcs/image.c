/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:54:07 by ylouvel           #+#    #+#             */
/*   Updated: 2024/02/25 23:14:12 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Affiche le joueur
void	display_player(t_data *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_player,
		vars->player.x, vars->player.y);
}

// Initie les images sur leur structure 
// (mur, sol, item, joueur)
void	load_images(t_data *vars)
{
	vars->img_map = mlx_xpm_file_to_image(vars->mlx, "../textures/barreau.xpm",
			&vars->width, &vars->height);
	vars->img_background = mlx_xpm_file_to_image(vars->mlx,
			"../textures/floor_jail.xpm", &vars->width, &vars->height);
	vars->img_item = mlx_xpm_file_to_image(vars->mlx,
			"../textures/booba_with_floor.xpm", &vars->width, &vars->height);
	vars->img_player = mlx_xpm_file_to_image(vars->mlx,
			"../textures/kaaris_with_floor.xpm", &vars->width, &vars->height);
}

// Affiche les images sur la map (elle est appeller dans read_and_display_map())
void	display_map_element(char buffer, int x, int y, t_data *vars)
{
	if (buffer == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_map, x, y);
	if (buffer == '0' || buffer == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_background, x,
			y);
	if (buffer == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_item, x, y);
}

// Spawn du joueur en 80, 80 et appelle de load_image, read_map et display_player
void	push_img(t_data *vars, t_data *essential, int one_or_zero)
{
	int nb_line;
	nb_line = ft_strlen_sous_coke(essential->files.map);
	//printf("\nnb_line = %d ", (nb_line-1));
	if (one_or_zero >= (nb_line - 2))
	{
		load_images(vars);
		read_map(vars, essential->files.map);
		for_player(essential, vars, essential->files.map);
	}
	else
		exit(1);
}

//TODO: Le programme crash si j'appelle cette fonction donc il faudra regler le pb
// Detruit les images
void destroy_images(t_data vars) {
    mlx_destroy_image(vars.mlx, vars.img_map);
    mlx_destroy_image(vars.mlx, vars.img_background);
    mlx_destroy_image(vars.mlx, vars.img_item);
    mlx_destroy_image(vars.mlx, vars.img_player);
}
