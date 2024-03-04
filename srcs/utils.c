/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:53:56 by ylouvel           #+#    #+#             */
/*   Updated: 2024/02/29 02:34:53 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Prend la largeur de la map
int	largeur_map(t_data *vars)
{
	int		hauteur;
	char	buffer;
	int		fd;

	hauteur = 0;
	if (vars == NULL || vars->map == NULL)
	{
		perror("Error: invalid pointer or map file");
		exit(1);
	}
	fd = open(vars->map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening fileEE");
		exit(1);
	}
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			hauteur++;
	}
	hauteur++;
	close(fd);
	return (hauteur);
}

// Normalement le probleme est regler mais pas sur a 100%
int	ft_strlen_sous_coke(char *map)
{
	int		nb_line;
	char	buffer;
	int		fd;

	nb_line = 0;
	fd = open(map, O_RDONLY);
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			break ;
		nb_line++;
	}
	close(fd);
	return (nb_line - 1);
}

char	call_get_map_value(int x, int y, char *map)
{
	int		fd;
	int		nb_line;

	nb_line = ft_strlen_sous_coke(map);
	fd = open(map, O_RDONLY);
	return (get_map_value(x, y, fd, nb_line));
	close(fd);
}

//! SERT A TROUVE LES ELEMENTS DANS LA MAP !!!
//(sinn elle sert a renvoyer le buffer de la map et SERT A TROUVE LES ELEMENTS DANS LA MAP !!!)
char	get_map_value(int x, int y, int fd, int nb_line)
{
	char	buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (read(fd, &buffer, 1) > 0 && i <= nb_line)
	{
		if (buffer == '\n')
		{
			i++;
			j = 0;
		}else
		{		
			if (i == y && j == x)
			{
				if (buffer == 'C')
					printf("objet trv !");
				//printf("%d %d ", i, j); //! POSITION DU JOUEUR EN TEMPS REEL
				//printf(" %c ", buffer); //! SERT A TROUVE LES ELEMENTS DANS LA MAP !!!
				close(fd);
				return (buffer);
			}
			j++;
		}
	}
	close(fd);
	return (' ');
}

void 	for_update_coordinates(int *j, int *x, int *y, char *map)
{
	int		nb_line;
	char	buffer;
	int		fd;

	nb_line = 0;
	fd = open(map, O_RDONLY);
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			break ;
		nb_line++;
	}
	close(fd);
	nb_line--;
	update_coordinates(j, x, y, nb_line);
}

// Initie les varible pour lire la map (utiliser dans read_and_display_map())
void	update_coordinates(int *j, int *x, int *y, int nb_line)
{
	(*j)++;
	(*x) += 80;
	if (*j == nb_line)
	{
		*j = 0;
		(*y) += 80;
		(*x) = 0;
	}
}

// TODO: Ajouter le clear des images
// Ferme la fenetre proprement :)
int	cross_close(t_data *vars)
{
	destroy_images(vars);
	return (0);
}

// Initie les tableau a 0 pour le backtracking
void	*ft_memset(void *str, int value, size_t len)
{
	unsigned char	*str_temp;

	str_temp = (unsigned char *)str;
	while (len > 0)
	{
		*(str_temp++) = (unsigned char)value;
		len--;
	}
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;
	dest = NULL;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	i = 0;
	if (!dest[i])
	{
		free(dest);
		return (NULL);
	}
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
