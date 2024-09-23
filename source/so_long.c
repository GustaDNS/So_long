/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:21:35 by gudaniel          #+#    #+#             */
/*   Updated: 2024/09/23 16:01:05 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2)
	{
		map = init();
		make_struct(argv[1], map);
		parsing(map, argv[1]);
	}
	return (0);
}

//TODO: remove "perror" and replace for exit