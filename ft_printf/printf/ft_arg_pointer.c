/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 08:27:00 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/21 11:56:56 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../library/ft_printf.h"

static void	ft_conv_ptr(unsigned long long num)
{
	char	*hex_dig;
	char	buffer[20];
	int		i;

	hex_dig = "0123456789abcdef";
	i = 0;
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	while (num != 0)
	{
		buffer[i++] = hex_dig[num % 16];
		num /= 16;
	}
	while (i--)
	{
		ft_putchar_fd(buffer[i], 1);
	}
}

static int	ft_hex_len(unsigned long long num)
{
	int	len;

	len = 0;
	while (num)
	{
		len++;
		num /= 16;
	}
	return (len);
}

int	ft_print_p(unsigned long long num)
{
	int	print_length;

	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	print_length = 0;
	print_length += write(1, "0x", 2);
	if (num == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_conv_ptr(num);
		print_length += ft_hex_len(num);
	}
	return (print_length);
}
