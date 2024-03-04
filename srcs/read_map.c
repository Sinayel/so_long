/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:53:54 by ylouvel           #+#    #+#             */
/*   Updated: 2024/02/27 21:02:58 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//! PROBLEME: Trop d'appelle de fd
// Verifie le fd et envoie la hauteur et le fd sur read_and_display
void	read_map(t_data *vars, char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening fileee !!!!!\n");
		exit(1);
	}
	read_and_display_map(fd, vars, map);
	printf("Fin de la lecture de la carte\n");
	close(fd);
}

// Lis et affiche la carte
void	read_and_display_map(int fd, t_data *vars, char *map)
{
	char	buffer;
	int		j;
	int		x;
	int		y;
	int		i;

	j = 0;
	x = 0;
	y = 0;
	i = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == 'E')
			i++;
		if (buffer == '1' || buffer == '0' || buffer == 'C' || buffer == 'P'
			|| buffer == 'E')
		{
			display_map_element(buffer, x, y, vars);
			for_update_coordinates(&j, &x, &y, map);
		}
		if (buffer == 'E' && i > 1)		//! Rajouter une fonction pour gerer les erreurs
			exit(1);
	}
	close(fd);
}

int	number_of_c(char *map)
{
	int		i;
	char	buffer;
	int		fd;

	fd = open(map, O_RDONLY);
	i = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == 'C')
			i++;
	}
	printf("\ni = %d\n", i);
	close(fd);
	return (i);
}

int	number_of_e(char *map)
{
	int		i;
	char	buffer;
	int		fd;

	fd = open(map, O_RDONLY);
	i = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == 'E')
			i++;
	}
	close(fd);
	return (i);
}
