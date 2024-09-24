/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:27:24 by gudaniel          #+#    #+#             */
/*   Updated: 2024/09/24 11:44:02 by gudaniel         ###   ########.fr       */
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
	while (++i < map->height)
	{
		while (++j < map->width)
		{
			if (map->map[i][j] == 'P')
				player++;
			if (map->map[i][j] == 'E')
				exit++;
			if (map->map[i][j] == 'C')
				collectible++;
		}
		j = -1;
	}
	if (player != 1 || exit != 1 || collectible == 0)
	{
		ft_printf("Error\n");
		killua(map);
	}
}

void	validate_walls(t_map *map)
{
	int	i;
	int	j;
	int	bi;

	i = 0;
	j = -1;
	bi = 0;
	while (map->map[0][++j] != '\n')
		if (map->map[0][j] != '1')
			bi = 1;
	j = -1;
	while (map->map[++i])
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			bi = 1;
	while (map->map[i - 1][++j])
		if (map->map[map->height - 1][j] != '1')
			bi = 1;
	if (bi == 1)
	{
		ft_printf("Error\n");
		killua(map);
	}
}

void	validate_format(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[0] == '/' || file[i - 4] != '.'
		|| file[i - 3] != 'b' || file[i - 2] != 'e' || file[i - 1] != 'r')
	{
		free(file);
		ft_printf("Error\n");
		exit(1);
	}
}

void	make_struct(char *file, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	map->height = set_height(fd);
	set_map(map, file);
	set_width(map);
}

void	validate_chr(t_map *map, int i, int j)
{
	while (i < map->height)
	{
		while (j < map->width)
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0'
				&& map->map[i][j] != 'P' && map->map[i][j]
				!= 'E' && map->map[i][j] != 'C')
			{
				ft_printf("Error\n");	
				killua(map);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
