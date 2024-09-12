/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:45:49 by gudaniel          #+#    #+#             */
/*   Updated: 2024/09/12 16:03:23 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	validate_elements(t_map *map, int i, int j)
{
	int	player;
	int	exit;
	int	collectible;

	player = 0;
	exit = 0;
	collectible = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
				player++;
			if (map->map[i][j] == 'E')
				exit++;
			if (map->map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	if (player != 1 || exit != 1 || collectible == 0)
		perror("Invalid map");
}

void	validate_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
			{
				if (map->map[i][j] != '1')
					perror("Invalid map");
			}
			j++;
		}
		i++;
	}
}

void	validate_format(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[0] == '/' || file[i - 4] != '.' || file[i - 3] != 'b' || file[i - 2] != 'e' || file[i - 1] != 'r')
		perror("Invalid file format");
}

void	is_rectangular(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->map[i]) != (size_t)map->width)
			perror("Invalid map");
		i++;
	}
}

