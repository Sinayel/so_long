/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:38:49 by ylouvel           #+#    #+#             */
/*   Updated: 2024/02/25 21:48:23 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//TODO: Changer la position de depart de la verif pour quelle commence a la position du joueur
int	backtracking(char *Rmap)
{
	char	map[SIZE][SIZE];
	int		visited[SIZE][SIZE] = {0};
	int		visited_p[SIZE][SIZE] = {0};
	int		visited_e[SIZE][SIZE] = {0};

	int result_c, result_p, result_e;
	if (open_file_read(Rmap, map) == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (EXIT_FAILURE);
	}
	result_c = verif_map_for_C(map, visited, 1, 1);
	result_p = verif_map_for_P(map, visited_p, 1, 1);
	result_e = verif_map_for_E(map, visited_e, 1, 1);

	if (result_c == 1 && result_e == 1 && result_p == 1)
		return (1);
	else
	{
		printf("Erreur : les caractères 'C', 'P' et 'E' ne sont pas présents\n");
		return (0);
	}
}

// Fonction pour ouvrir et lire le fichier
int	open_file_read(char *filename, char map[][SIZE])
{
	int		fd;
	char	cell;
	ssize_t	bytes_read;
	int		x = 0, y;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (-1);
	}
	x = 0, y = 0;
	while ((bytes_read = read(fd, &cell, 1)) > 0)
	{
		if (cell == '\n')
		{
			x++;
			y = 0;
			continue ;
		}
		map[x][y++] = cell;
	}
	close(fd);
	return (0);
}

int	verif_map_for_C(char map[SIZE][SIZE], int visited[SIZE][SIZE], int x, int y)
{
	int	found_CPE;

	if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || map[x][y] == '1'
		|| visited[x][y] == 1)
		return (0);
	visited[x][y] = 1;
	printf("(%d, %d)\n", x, y);
	if (map[x][y] == 'C')
	{
		map[x][y] = ' ';
		return (1);
	}
	found_CPE = 0;
	found_CPE |= verif_map_for_C(map, visited, x - 1, y); // vers le ^
	found_CPE |= verif_map_for_C(map, visited, x + 1, y); // vers le v
	found_CPE |= verif_map_for_C(map, visited, x, y - 1); // vers la <
	found_CPE |= verif_map_for_C(map, visited, x, y + 1); // vers la >
	return (found_CPE);
}

int	verif_map_for_P(char map[SIZE][SIZE], int visited[SIZE][SIZE], int x, int y)
{
	int	found_CPE;

	if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || map[x][y] == '1'
		|| visited[x][y] == 1)
		return (0);
	visited[x][y] = 1;
	printf("(%d, %d)\n", x, y);
	if (map[x][y] == 'P')
	{
		map[x][y] = ' ';
		return (1);
	}
	found_CPE = 0;
	found_CPE |= verif_map_for_P(map, visited, x - 1, y); // vers le ^
	found_CPE |= verif_map_for_P(map, visited, x + 1, y); // vers le v
	found_CPE |= verif_map_for_P(map, visited, x, y - 1); // vers la <
	found_CPE |= verif_map_for_P(map, visited, x, y + 1); // vers la >
	return (found_CPE);
}

int	verif_map_for_E(char map[SIZE][SIZE], int visited[SIZE][SIZE], int x, int y)
{
	int	found_CPE;

	if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || map[x][y] == '1'
		|| visited[x][y] == 1)
		return (0);
	visited[x][y] = 1;
	printf("(%d, %d)\n", x, y);
	if (map[x][y] == 'E')
	{
		map[x][y] = ' ';
		return (1);
	}
	found_CPE = 0;
	found_CPE |= verif_map_for_E(map, visited, x - 1, y); // vers le ^
	found_CPE |= verif_map_for_E(map, visited, x + 1, y); // vers le v
	found_CPE |= verif_map_for_E(map, visited, x, y - 1); // vers la <
	found_CPE |= verif_map_for_E(map, visited, x, y + 1); // vers la >
	return (found_CPE);
}
