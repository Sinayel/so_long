/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:27:39 by ylouvel           #+#    #+#             */
/*   Updated: 2024/02/25 23:12:35 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//TODO: Faire un 2eme fichier de verif map pour avoir 5 fonctions par fichier

int     return_yes_or_no(char *buffer, char *buf)
{
    int i;
    i = 0;
    while(buffer[i] && buf[i])
    {
        compteur_line(buf);
        if (buffer[i] != '1' || buf[i] != '1')
        {
            printf("unavailable map, please retry with good map !");
            return -1;
        }
        i++;
    }
    return 1;
}

void    stock_size_of_buffer(char *buffer)
{
    int i;
    char *tmp = NULL;
    i = 0;
    while (buffer[i])
    {
        tmp[i] = buffer[i];
        i++;
    }
    compteur_line_last(tmp);
}

int     return_yes_or_no_for_side_right(t_data *essential, char *side)
{
    int i;
    int nb_line;
    nb_line = ft_strlen_sous_coke(essential->files.map);
    i = 0;
    while(i < nb_line)
    {
        if (side[nb_line - 1] != '1')
        {
            printf("unavailable map, please retry with a very good map !");
            return (0);
        }
        else if (side[0] != '1')
        {
            printf("unavailable map, please retry with a very good map !");
            return (0);
        }
        else if (i > nb_line)
            return (0);
        i++;
    }
    return (1);
}

int    for_verif_exterior(char *map, t_data *essential)
{
    int fd;
    int nb_line = largeur_map(essential);
    int return_value;
    return_value = 0;
    fd = open(map, O_RDONLY);
    return_value = verif_exterior(essential, nb_line, fd);
    return (return_value);
}

int    compteur_line(char *side)
{
    int i;

    i = 0;
    while (side[i] != '\n')
    {
        if (i > 13)
            return -2000;
        i++;
    }
    return 1;
}

int    compteur_line_last(char *side)
{
    int i;

    i = 0;
    while (side[i])
        i++;
    if (i > 13 || i < 13)
        return -767;
    return 1;
}

int     verif_exterior(t_data *essential, int nb_line, int fd)
{
    int i;
    char *buffer;
    char *buf;
    char *side;
    int y_n;

    y_n = 0;
    i = 0;
    while ((i - 1) <= (nb_line - 1))
    {
        if (i == 0) //* Verifie la premiere ligne de la map
            buf = get_next_line(fd);
        else if (i < (nb_line - 1)) //* Incremente le reste de la map pour aller jusqu'a la derniere ligne
        {
            side = get_next_line(fd);
            y_n += compteur_line(side);
            y_n += return_yes_or_no_for_side_right(essential, side);
        }
        else if (i == nb_line) //* Verifie la derniere ligne de la map
            buffer = get_next_line(fd);
        i++;
    }
    y_n += return_yes_or_no(buffer, buf) + compteur_line_last(buffer);
    close(fd);
    return (y_n);
}
