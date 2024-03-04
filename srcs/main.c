/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:53:51 by ylouvel           #+#    #+#             */
/*   Updated: 2024/03/04 17:06:48 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


// Appelle de push_img et iniatilisation de la fenetre
int	main(void)
{
	//t_player player;
	//t_sortie sortie;
	t_data	vars;
	int		yes;

	//memset(&sortie, 0, sizeof(sortie));
	//memset(&player, 0, sizeof(player));
	memset(&vars, 0, sizeof(vars));
	vars.map = "../map/map2.ber";

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1280, 720, "Title");
	//yes = for_verif_exterior("../map/map2.ber", &vars);
	//if (for_backtracking("../map/map2.ber") != 1)
	//	destroy_images(&vars);
	push_img(&vars, yes);
	mlx_hook(vars.win, 2, 1L << 0, key, &vars);
	mlx_hook(vars.win, 17, 0, cross_close, &vars);
	mlx_loop(vars.mlx);
	destroy_images(&vars);
	mlx_destroy_display(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	return (0);
}
