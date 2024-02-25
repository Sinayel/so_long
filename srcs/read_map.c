/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:53:54 by ylouvel           #+#    #+#             */
/*   Updated: 2024/02/25 23:10:03 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//! PROBLEME: Trop d'appelle de fd
// Verifie le fd et envoie la hauteur et le fd sur read_and_display
void	read_map(t_data *vars, char *map)
{
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file !\n");
		exit(1);
	}
	read_and_display_map(fd, vars, map);
	printf("Fin de la lecture de la carte\n");
	close(fd);
}

// Lis et affiche la carte en utilisant  display_map_element et update_coordinates
void	read_and_display_map(int fd, t_data *vars, char *map)
{
	char	buffer;
	int		j;
	int		x;
	int		y;

	j = 0;
	x = 0;
	y = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '1' || buffer == '0' || buffer == 'C' || buffer == 'P')
		{
			display_map_element(buffer, x, y, vars);
			for_update_coordinates(&j, &x, &y, map);
		}
	}
	close(fd);
}
