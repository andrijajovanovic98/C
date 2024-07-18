/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilstwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:34:47 by ajovanov          #+#    #+#             */
/*   Updated: 2024/07/16 14:34:52 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	exit_free_one(t_stk **stack, int mode, char **sp, int argc)
{
	t_stk	*temp;

	if (mode == 0)
		write(2, "Error\n", 6);
	if (stack)
	{
		while (*stack)
		{
			temp = (*stack)->next;
			free(*stack);
			*stack = temp;
		}
	}
	if (argc == 2)
		free_splitt(sp);
	if (mode == 0 || mode == 1)
		exit(0);
}
