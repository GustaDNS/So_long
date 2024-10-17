/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:59:24 by gudaniel          #+#    #+#             */
/*   Updated: 2024/04/25 17:44:14 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t n)
{
	size_t	i;
	size_t	sized;
	size_t	sizes;

	sized = ft_strlen(dst);
	if (!dst)
		sized = 0;
	sizes = ft_strlen(src);
	i = 0;
	if (n == 0 || sized > n)
		return (sizes + n);
	while ((src[i]) && ((i + sized) < n - 1))
	{
		dst[sized + i] = src[i];
		i++;
	}
	dst[sized + i] = '\0';
	return (sized + sizes);
}
