/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 08:25:56 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/21 08:26:10 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_argument_s(char *string)
{
	int	i;

	i = 0;
	if (string == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
	}
	return (i);
}
