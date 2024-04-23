/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 08:40:14 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/22 16:10:00 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_check_arguments(va_list arg, char chr)
{
	int	bytes;

	bytes = 0;
	if (chr == 'c')
		bytes += ft_argument_c(va_arg(arg, int));
	if (chr == 's')
		bytes += ft_argument_s(va_arg(arg, char *));
	else if (chr == 'd' || chr == 'i')
		bytes += ft_printnbr(va_arg(arg, int));
	else if (chr == 'p')
		bytes += ft_print_p(va_arg(arg, unsigned long long));
	else if (chr == 'u')
		bytes += ft_arg_unsignedint(va_arg(arg, unsigned int));
	else if (chr == 'x' || chr == 'X')
		bytes += ft_prt_hex(va_arg(arg, unsigned int), chr);
	else if (chr == '%')
		bytes += write(1, "%", 1);
	return (bytes);
}

int	ft_to_be_shorter(const char *str, va_list arg)
{
	int		i;
	int		bytes;
	char	c;

	i = 0;
	bytes = 0;
	while (str[i])
	{
		c = str[i + 1];
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (-1);
			bytes += ft_check_arguments(arg, c);
			i++;
		}
		else
		{
			bytes += write(1, &str[i], sizeof(char));
		}
		i++;
	}
	return (bytes);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	int			bytes;

	if (!str)
		return (-1);
	va_start(arg, str);
	bytes = ft_to_be_shorter(str, arg);
	va_end (arg);
	return (bytes);
}
