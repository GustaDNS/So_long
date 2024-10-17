/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:55:10 by gudaniel          #+#    #+#             */
/*   Updated: 2024/04/22 19:57:37 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*str;

	if (((nitems > 2147483647 && size != 0)
			|| (size > 2147483647 && nitems != 0)))
		return (NULL);
	str = malloc (nitems * size);
	if (!str)
		return (NULL);
	ft_bzero(str, size * nitems);
	return (str);
}
