/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_integer_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 08:27:47 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/21 10:32:14 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len])
		len++;
	write (1, str, len);
	return (len);
}

int	ft_printnbr(int number)
{
	char	*num;
	int		len;

	len = 0;
	num = ft_itoa(number);
	len = len + ft_putstr(num);
	free(num);
	return (len);
}
