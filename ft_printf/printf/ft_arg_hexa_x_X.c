/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_x_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 08:29:52 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/21 08:30:10 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../library/ft_printf.h"

static int	ft_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	ft_conv_hex(unsigned int n, char format)
{
	if (n >= 16)
		ft_conv_hex(n / 16, format);
	if (n % 16 < 10)
		ft_putchar_fd((n % 16) + '0', 1);
	else if (format == 'x')
		ft_putchar_fd((n % 16) - 10 + 'a', 1);
	else if (format == 'X')
		ft_putchar_fd((n % 16) - 10 + 'A', 1);
}

int	ft_prt_hex(unsigned int n, const char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	ft_conv_hex(n, format);
	return (ft_len(n));
}
