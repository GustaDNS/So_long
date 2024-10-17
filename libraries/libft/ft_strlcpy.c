/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:59:32 by gudaniel          #+#    #+#             */
/*   Updated: 2024/04/09 13:59:35 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, char *src, size_t n)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(src);
	i = 0;
	if (!dst || !src)
		return (0);
	if (n == 0)
		return (size);
	while ((src[i]) && (i < n - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size);
}
