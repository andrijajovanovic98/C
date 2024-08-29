/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:35:07 by ajovanov          #+#    #+#             */
/*   Updated: 2024/08/26 18:35:10 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "piloshopers.h"

int	is_number(char num)
{
	return (num >= '0' && num <= '9');
}

int	in_range(int num)
{
	return (num >= 0 && num <= 2147483647);
}

long int	ft_atoi(char *str)
{
	int			i;
	long int	num;

	i = 0;
	num = 0;
	while (is_number(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num);
}
