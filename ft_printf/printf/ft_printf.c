/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 08:40:14 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/21 08:40:26 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_check_arguments(va_list arg, char c)
{
	int	bytes;

	bytes = 0;
	if (c == 'c')
		bytes += ft_argument_c(va_arg(arg, int));
	if (c == 's')
		bytes += ft_argument_s(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		bytes += ft_printnbr(va_arg(arg, int));
	else if (c == 'p')
		bytes += ft_print_p(va_arg(arg, unsigned long long));
	else if (c == 'u')
		bytes += ft_arg_unsignedint(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		bytes += ft_prt_hex(va_arg(arg, unsigned int), c);
	else if (c == '%')
		bytes += write(1, "%", 1);
	return (bytes);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	int			i;
	int			bytes;
	char		c;

	i = 0;
	bytes = 0;
	va_start(arg, str);
	while (str[i])
	{
		c = str[i + 1];
		if (str[i] == '%')
		{
			bytes += ft_check_arguments(arg, c);
			i++;
		}
		else
			bytes += write(1, &str[i], sizeof(char));
		i++;
	}
	va_end(arg);
	return (bytes);
}
