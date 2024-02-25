/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:53:51 by ylouvel           #+#    #+#             */
/*   Updated: 2024/02/25 23:24:28 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// // Compteur de fd
// int count_open_fds() {
//     int fds = 0;
//     FILE *fp;
//     char path[1024];
//     char buffer[1024];

//     snprintf(path, sizeof(path), "/proc/%d/fd", getpid());

//     fp = popen("ls -l /proc/self/fd | wc -l", "r");
//     if (fp == NULL) {
//         perror("Erreur lors de l'ouverture du fichier /proc/self/fd");
//         return -1;
//     }

//     if (fgets(buffer, sizeof(buffer), fp) != NULL)
//         fds = atoi(buffer);

//     pclose(fp);

//     return fds;
// }

// Appelle de push_img et iniatilisation de la fenetre
int	main(void)
{
	t_data	vars;
    t_data  essential;
    int yes;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1280, 720, "Title");

    // Fonction principal   
    essential.files.map = "../map/map2.ber";
    yes = for_verif_exterior("../map/map2.ber", &essential); //* Verif Exterieur FINI !!
	if (backtracking("../map/map2.ber") != 1)
		exit(1);
	push_img(&vars, &essential, yes);

	mlx_hook(vars.win, 2, 1L << 0, key, &vars);
	mlx_hook(vars.win, 17, 0, cross_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
