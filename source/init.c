/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:35:58 by gudaniel          #+#    #+#             */
/*   Updated: 2024/09/24 11:59:54 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game(t_map *map)
{
	map->map = NULL;
	map->width = 0;
	map->height = 0;
}

t_map	*init(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		killua(map);
	init_game(map);
	return (map);
}
