/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:10:48 by ael-hadj          #+#    #+#             */
/*   Updated: 2024/12/22 18:12:31 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int is_upper)
{
	char	*low_hex;
	char	*upper_hex;
	int		count;

	upper_hex = "0123456789ABCDEF";
	low_hex = "0123456789abcdef";
	count = 0;
	if (is_upper == 1)
	{
		if (n >= 16)
			count += ft_puthex((n / 16), 1);
		count += ft_putchar(upper_hex[n % 16]);
	}
	else if (is_upper == 0)
	{
		if (n >= 16)
			count += ft_puthex((n / 16), 0);
		count += ft_putchar(low_hex[n % 16]);
	}
	return (count);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
