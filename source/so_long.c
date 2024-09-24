/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:21:35 by gudaniel          #+#    #+#             */
/*   Updated: 2024/09/24 11:34:21 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2)
	{
		map = init();
		if (!map)
			killua(map);
		make_struct(argv[1], map);
		parsing(map, argv[1]);
		killua(map);
	}
	return (0);
}

//TODO: remove "perror" and replace for exit