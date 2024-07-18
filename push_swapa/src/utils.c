/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:36:18 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/17 16:37:02 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	poz;

	poz = 0;
	while (str[poz] != '\0')
	{
		write(1, &str[poz], 1);
		poz++;
	}
}

void	exit_free(t_stk **stack_a, t_stk **stack_b, int mode, char **sp)
{
	t_stk	*temp;

	if (mode == 0)
		write(2, "Error\n", 6);
	if (stack_a)
	{
		while (*stack_a)
		{
			temp = (*stack_a)->next;
			free(*stack_a);
			*stack_a = temp;
		}
	}
	free_splitt(sp);
	if (stack_b)
	{
		while (*stack_b)
		{
			temp = (*stack_b)->next;
			free(*stack_b);
			*stack_b = temp;
		}
	}
	if (mode == 0 || mode == 1)
		exit(0);
}

long int	ft_atoi(t_stk **stack_a, char *str)
{
	long int	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		exit_free(stack_a, NULL, 0, NULL);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * sign);
}

int	abs(int number)
{
	if (number < 0)
		return (number * -1);
	else
		return (number);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}
