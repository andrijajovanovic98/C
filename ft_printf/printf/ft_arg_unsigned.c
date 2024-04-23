/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 08:28:58 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/21 08:29:13 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	ft_intlen(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*atoi_unsignedint(unsigned int n)
{
	char		*str;
	size_t		len;
	long int	num;

	num = n;
	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = num % 10 + '0';
		num = num / 10;
	}
	return (str);
}

int	ft_arg_unsignedint(unsigned int n)
{
	int		len;
	char	*number;

	number = atoi_unsignedint(n);
	if (number == 0)
		return (0);
	len = write(1, number, ft_intlen(n));
	free(number);
	return (len);
}
