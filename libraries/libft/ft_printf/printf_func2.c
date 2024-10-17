/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_func2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:57:51 by gudaniel          #+#    #+#             */
/*   Updated: 2024/05/03 10:58:37 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbruns(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbruns(n / 10);
		count += ft_putnbruns(n % 10);
	}
	else
		count += ft_putchar(n + 48);
	return (count);
}

int	ft_putdeci(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbruns(n / 10);
		count += ft_putnbruns(n % 10);
	}
	else
		count += ft_putchar(n + 48);
	return (count);
}
