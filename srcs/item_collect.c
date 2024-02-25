/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_collect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:41:59 by ylouvel           #+#    #+#             */
/*   Updated: 2024/02/14 04:49:54 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Met à jour la valeur de la carte a la position donnee
void	update_map_value(int x, int y, char *map, char new_value)
{
	int		fd;
	int		nb_line;
	int		i;
	int		j;
	off_t	start_of_line;
	off_t	current_position;
	char	buffer;

	i = 0;
	j = 0;
	start_of_line = 0;
	current_position = 0;
	nb_line = calculate_line_length(map);
	fd = open_map_file(map);
	while (read(fd, &buffer, 1) > 0 && i <= nb_line)
	{
		if (buffer == '\n')
		{
			i++;
			j = 0;
			start_of_line = current_position + 1;
		}
		else
		{
			if (i == y && j == x)
			{
				seek_to_position(fd, start_of_line + j);
				write_new_value(fd, new_value);
				break ;
			}
			j++;
		}
		current_position++;
	}
	close_map_file(fd);
}

// Ouvre le fichier de la carte
int	open_map_file(char *map)
{
	int	fd;

	fd = open(map, O_RDWR);
	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		exit(0);
	}
	return (fd);
}

// Calcule la longueur de la ligne de la carte
int	calculate_line_length(char *map)
{
	int	nb_line;

	nb_line = 0;
	while (map[nb_line] != '\n' && map[nb_line] != '\0')
	{
		nb_line++;
	}
	return (nb_line);
}

// Ferme le fichier de la carte
void	close_map_file(int fd)
{
	if (close(fd) == -1)
	{
		perror("Erreur lors de la fermeture du fichier");
		exit(0);
	}
}

// Fonction pour se positionner dans le fichier
void	seek_to_position(int fd, off_t position)
{
	if (lseek(fd, position, SEEK_SET) == -1)
	{
		perror("Erreur lors de la recherche de la position dans le fichier");
		close(fd);
		exit(0);
	}
}

// Ecrit la nouvelle valeur dans le fichier
void	write_new_value(int fd, char new_value)
{
	if (write(fd, &new_value, 1) == -1)
	{
		perror("Erreur lors de l'ecriture dans le fichier");
		close(fd);
		exit(0);
	}
}
