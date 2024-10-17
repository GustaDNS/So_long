/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:56:48 by gudaniel          #+#    #+#             */
/*   Updated: 2024/04/09 13:56:53 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ms;

	ms = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		if (ms[i] == (unsigned char)c)
			return (ms + i);
		i++;
		n--;
	}
	return (NULL);
}
