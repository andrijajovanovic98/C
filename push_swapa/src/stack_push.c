/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:35:03 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/17 16:35:17 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push(t_stk **source, t_stk **dest)
{
	t_stk	*node;

	if (!(*source))
		return ;
	node = *source;
	*source = (*source)->next;
	if (*dest == NULL)
	{
		*dest = node;
		(*dest)->next = NULL;
	}
	else
	{
		node->next = *dest;
		*dest = node;
	}
}

void	do_push(t_stk **stk_a, t_stk **stk_b, char name, int *cost)
{
	if (name == 'a')
	{
		push(stk_b, stk_a);
		ft_putstr("pa\n");
	}
	else if (name == 'b')
	{
		push(stk_a, stk_b);
		ft_putstr("pb\n");
		(*cost)++;
	}
}

void	rotate(t_stk **stack)
{
	t_stk	*new_last;
	t_stk	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	new_last = *stack;
	while (new_last->next != NULL)
		new_last = new_last->next;
	temp->next = NULL;
	new_last->next = temp;
}

void	do_rotate(t_stk **stack_a, t_stk **stack_b, char operation, int *cost)
{
	if (operation == 'x')
	{
		rotate(stack_a);
		ft_putstr("ra\n");
	}
	if (operation == 'a' || operation == 'r')
	{
		rotate(stack_a);
		if (operation == 'a')
		{
			ft_putstr("ra\n");
			(*cost)--;
		}
	}
	if (operation == 'b' || operation == 'r')
	{
		rotate(stack_b);
		if (operation == 'b')
		{
			ft_putstr("rb\n");
			(*cost)--;
		}
	}
	if (operation == 'r')
		ft_putstr("rr\n");
}

void	do_rotate_ab(t_stk **a, t_stk **b, int *cost)
{
	if (b == NULL)
	{
		while (*cost)
		{
			if (*cost > 0)
				do_rotate(a, NULL, 'a', cost);
			else
				do_rev_rotate(a, NULL, cost);
		}
	}
	if (a == NULL)
	{
		while (*cost)
		{
			if (*cost > 0)
				do_rotate(NULL, b, 'b', cost);
			else
				do_rev_rotate(NULL, b, cost);
		}
	}
}
