/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 23:25:48 by ylouvel           #+#    #+#             */
/*   Updated: 2024/02/25 23:11:02 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	for_player(t_data *essential, t_data *vars, char *map)
{
	int fd;

	fd = open(essential->files.map, O_RDONLY);
	read_for_player(vars, fd, map);
	close(fd);
}

void	read_for_player(t_data *vars, int fd, char *map)
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
		if (buffer == '1' || buffer == '0' || buffer == 'C')
			for_update_coordinates(&j, &x, &y, map);
		if (buffer == 'P')
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img_player, x, y);
			vars->player.y = y;
			vars->player.x = x;
		}
	}
	close(fd);
}
