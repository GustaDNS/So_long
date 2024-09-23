/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:42:47 by gudaniel          #+#    #+#             */
/*   Updated: 2024/09/23 16:02:16 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/libft.h"
# include "../libraries/minilibx-linux/mlx.h"
# include <stdbool.h>

//--------------------MAP----------------------//
typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}	t_map;

void	validate_format(char *file);
void	validate_walls(t_map *map);
void	validate_elements(t_map *map, int i, int j);
void	parsing(t_map *map, char *file);
//-------------------GAME--------------------//

t_map	*init(void);
void	init_game(t_map *map);
void	floodfill(t_map *map, int x, int y);
int		set_height(int fd);
void	set_map(t_map *map, char *file);
void	make_struct(char *file, t_map *map);
void	set_width(t_map *map);
void	validate_chr(t_map *map, int i, int j);

#endif