/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:42:47 by gudaniel          #+#    #+#             */
/*   Updated: 2024/08/21 15:23:30 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/libft.h"
# include "../libraries/libft/get_next_line/get_next_line.h"
# include "../libraries/libft/ft_printf/ft_printf.h"
# include <stdbool.h>

//--------------------MAP----------------------//
typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}	t_map;
void	is_rectangular(t_map *map);
void	validate_format(char *file);
void	validate_walls(t_map *map);
void	validate_elements(t_map *map);
void	read_map(t_map *map, char *file);
void	parsing(t_map *map, char *file);

#endif