/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:38:49 by ylouvel           #+#    #+#             */
/*   Updated: 2024/03/04 16:02:22 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	for_backtracking(char *Rmap)
{
	int	result_c;
	int	result_p;
	int	result_e;
	int	result;

	result_c = 0;
	result_p = 0;
	result_e = 0;
	result = backtracking(Rmap, result_c, result_c, result_p);
	return (result);
}

int	backtracking(char *Rmap, int result_c, int result_e, int result_p)
{
	char	map[SIZE][SIZE];
	int		visited[SIZE][SIZE];
	int		visited_p[SIZE][SIZE];
	int		visited_e[SIZE][SIZE];

	memset(visited, 0, sizeof(visited));
	memset(visited_e, 0, sizeof(visited_e));
	memset(visited_p, 0, sizeof(visited_p)); 
	if (open_file_read(Rmap, map) == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (EXIT_FAILURE);
	}
	result_c = verif_map_for_c(map, visited, 1, 1);
	result_p = verif_map_for_p(map, visited_p, 1, 1);
	result_e = verif_map_for_e(map, visited_e, 1, 1);
	if (result_c == 1 && result_e == 1 && result_p == 1)
		return (1);
	else
	{
		printf("Erreur : sur les caractères 'C', 'P' et 'E'\n");
		return (0);
	}
}

// Fonction pour ouvrir et lire le fichier
int	open_file_read(char *filename, char map[][SIZE])
{
	int		fd;
	char	cell;
	int		x;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	x = 0;
	y = 0;
	while (read(fd, &cell, 1) > 0)
	{
		if (cell == '\n')
		{
			x++;
			y = 0;
			continue ;
		}
		map[x][y++] = cell;
	}
	if (close(fd) == -1) {
        perror("Erreur lors de la fermeture du fichier");
        return (-1);
    }
	return (0);
}
