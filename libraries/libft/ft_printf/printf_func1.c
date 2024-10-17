/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_func1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:48:57 by gudaniel          #+#    #+#             */
/*   Updated: 2024/05/03 10:58:45 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		count += ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
		count += ft_putnbr(n);
	}
	else if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
		count += ft_putchar(n + 48);
	return (count);
}

int	ft_putstr(char *s)
{
	int	i;
	int	res;

	res = 0;
	if (!s)
	{
		res += write(1, "(null)", 6);
		return (res);
	}
	i = 0;
	while (s[i] != '\0')
	{
		res += write(1, &s[i], 1);
		i++;
	}
	return (res);
}

int	ft_putptr(unsigned long n, int i)
{
	const char	*base;
	int			res;

	res = 0;
	base = "0123456789abcdef";
	if (!n)
	{
		res += write(1, "(nil)", 5);
		return (res);
	}
	if (i == 0)
	{
		res = 2;
		write(1, "0x", 2);
	}
	if (n >= 16)
	{
		res += ft_putptr(n / 16, 1);
		n = n % 16;
	}
	if (n < 16)
		res += ft_putchar(base[n]);
	return (res);
}

int	ft_puthex(unsigned int n, const char c)
{
	char	*base;
	int		res;

	res = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		res += ft_puthex(n / 16, c);
		res += ft_puthex(n % 16, c);
	}
	else
		res += ft_putchar(base[n]);
	return (res);
}
