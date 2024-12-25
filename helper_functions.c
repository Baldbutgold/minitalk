/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:27:48 by ael-hadj          #+#    #+#             */
/*   Updated: 2024/12/19 09:28:14 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		count++;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + 48);
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putunsigned(n / 10);
	count += ft_putchar((n % 10) + 48);
	return (count);
}

int	ft_treat_pointer(unsigned long pointer)
{
	int		count;
	char	*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (pointer >= 16)
		count += ft_treat_pointer(pointer / 16);
	if (pointer != 0)
		count += ft_putchar(hex[pointer % 16]);
	return (count);
}

int	ft_put_pointer(unsigned long pointer)
{
	int	count;

	if (!pointer)
		return (ft_putstr("(nil)"));
	count = 2;
	ft_putstr("0x");
	count += ft_treat_pointer(pointer);
	return (count);
}
