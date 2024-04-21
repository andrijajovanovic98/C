/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:55:54 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/08 14:55:03 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	dest;
	int	minus;

	i = 0;
	dest = 0;
	minus = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			minus = minus * -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		dest = (nptr[i] - '0') + (dest * 10);
		i++;
	}
	return (dest * minus);
}
