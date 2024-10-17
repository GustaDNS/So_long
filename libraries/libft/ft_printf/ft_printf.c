/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:39:15 by gudaniel          #+#    #+#             */
/*   Updated: 2024/05/03 11:06:09 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_format(char c, va_list arg)
{
	int	result;

	result = 0;
	if (!c)
		return (0);
	else if (c == 'c')
		result += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		result += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		result += ft_putptr(va_arg(arg, unsigned long), 0);
	else if (c == 'd' || c == 'i')
		result += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		result += ft_putdeci(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		result += ft_puthex(va_arg(arg, int), c);
	else if (c == '%')
		result += write(1, "%", 1);
	else
		return (0);
	return (result);
}

int	ft_printf(const char *s, ...)
{
	int		result;
	va_list	ap;

	result = 0;
	va_start(ap, s);
	while (*s != '\0')
	{
		while (*s != '%' && *s != '\0')
			result += write(1, s++, 1);
		if (*s != '\0' && ++s)
			result += ft_format(*(s++), ap);
	}
	va_end(ap);
	return (result);
}

/* int main()
{
	#include <stdio.h>
    char c = 'k'; // %c
    char *str = NULL; // %s
    int nbr = 16;// %d // %i
    unsigned int nbrr = 4294967295;// %u
    int *var; var = &nbr;// %p
    int b= 0xffffffff;// %x // %X
    // %%
    int i;
    i = ft_printf("Printf replica:\n| TEST TEXT |\n| Single Char: %c 
	|\n| String: %s |\n| Pointer Adress: %p |\n| Decimal: %d |\n| 
	Integer %i |\n| Unsign deci: %u |\n| 
	HexLower: %x |\n| HexUpper: %X |\n| Percentage sign: %% 
	|\n", c, str, var, nbr, nbr, nbrr, b, b);
    printf("\nReturn Value: %d", i);
    ///////////////////////////////
    i = printf("Printf replica:\n| TEST TEXT |\n| Single Char: %c 
	|\n| String: %s |\n| 
	Pointer Adress: %p |\n| Decimal: %d |\n| Integer %i |\n| Unsign 
	deci: %u |\n| HexLower: %x |\n| 
	HexUpper: %X |\n| Percentage sign: %% |\n", c, str, var, nbr, 
	nbr, nbrr, b, b);
    printf("\nReturn Value: %d", i);
    return (0);
} */