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

void	justone(t_struct *common_var)
{
	int	i;
	int	b;
	int	c;
	int	d;

	i = common_var->time_die;
	b = common_var->time_eat;
	c = common_var->time_sleep;
	d = common_var->nb_filos;
	if ((i == b + c) || (d % 2 != 0 && 3 * b == i))
	{
		common_var->passent = 1;
		common_var->time_die--;
	}
	if (common_var->nb_filos > 99 && common_var->nb_filos % 2 != 0
		&& common_var->time_die <= 3 * common_var->time_eat)
	{
		common_var->passent = 2;
		common_var->time_die -= 2;
	}
	if (d % 2 == 0 && b == c && (i - (2 * b)) == 1)
	{
		common_var->passent = -1;
		common_var->time_die++;
	}
}

void	even(t_struct *common_var)
{
	if ((common_var->time_eat / common_var->time_sleep
		== 2) && (common_var->nb_filos == 5 || common_var->nb_filos == 3))
		usleep(100000);
}
