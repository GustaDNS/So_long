/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:59:09 by gudaniel          #+#    #+#             */
/*   Updated: 2024/04/09 13:59:18 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	int		i;
	int		j;
	int		size;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	newstring = (char *)malloc(sizeof(char) * (size + 1));
	if (!newstring)
		return (0);
	i = -1;
	j = 0;
	while ((++i < size) && s1[i])
		newstring[i] = s1[i];
	while ((i < size) && s2[j])
	{
		newstring[i] = s2[j];
		i++;
		j++;
	}
	newstring[i] = '\0';
	return (newstring);
}
