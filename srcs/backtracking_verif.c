/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_verif.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:27:07 by ylouvel           #+#    #+#             */
/*   Updated: 2024/03/04 16:38:18 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	verif_map_for_c(char map[SIZE][SIZE], int visited[SIZE][SIZE], int x, int y)
{
	int	found;

	if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || map[x][y] == '1'
		|| visited[x][y] == 1)
		return (0);
	visited[x][y] = 1;
	if (map[x][y] == 'C')
	{
		map[x][y] = ' ';
		return (1);
	}
	found = 0;
	found |= verif_map_for_c(map, visited, x - 1, y);
	found |= verif_map_for_c(map, visited, x + 1, y);
	found |= verif_map_for_c(map, visited, x, y - 1);
	found |= verif_map_for_c(map, visited, x, y + 1);
	return (found);
}

int	verif_map_for_p(char map[SIZE][SIZE], int visited[SIZE][SIZE], int x, int y)
{
	int	found;

	if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || map[x][y] == '1'
		|| visited[x][y] == 1)
		return (0);
	visited[x][y] = 1;
	if (map[x][y] == 'P')
	{
		map[x][y] = ' ';
		return (1);
	}
	found = 0;
	found |= verif_map_for_p(map, visited, x - 1, y);
	found |= verif_map_for_p(map, visited, x + 1, y);
	found |= verif_map_for_p(map, visited, x, y - 1);
	found |= verif_map_for_p(map, visited, x, y + 1);
	return (found);
}

int	verif_map_for_e(char map[SIZE][SIZE], int visited[SIZE][SIZE], int x, int y)
{
	int	found;

	if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || map[x][y] == '1'
		|| visited[x][y] == 1)
		return (0);
	visited[x][y] = 1;
	if (map[x][y] == 'E')
	{
		map[x][y] = ' ';
		return (1);
	}
	found = 0;
	found |= verif_map_for_e(map, visited, x - 1, y);
	found |= verif_map_for_e(map, visited, x + 1, y);
	found |= verif_map_for_e(map, visited, x, y - 1);
	found |= verif_map_for_e(map, visited, x, y + 1);
	return (found);
}
