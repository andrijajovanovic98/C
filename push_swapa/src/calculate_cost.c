/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:22:03 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/17 16:22:06 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	do_low_cost_move(t_stk **stack_a, t_stk **stack_b)
{
	t_stk	*temp;
	t_var	var;

	temp = *stack_b;
	var.lowest_cost = 2147483647;
	while (temp)
	{
		var.total_cost = abs(temp->cost_a) + abs(temp->cost_b);
		if (var.total_cost < var.lowest_cost)
		{
			var.lowest_cost = var.total_cost;
			var.cost_a = temp->cost_a;
			var.cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	reverse_rotate_both_stacks(stack_a, stack_b, &var.cost_a, &var.cost_b);
	do_rotate_ab(stack_a, NULL, &var.cost_a);
	do_rotate_ab(NULL, stack_b, &var.cost_b);
	do_push(stack_a, stack_b, 'a', 0);
}

int	calculate_cost(int pos, int size)
{
	if (pos > size / 2)
		return ((size - pos) * -1);
	return (pos);
}

void	tiny_sort(t_stk **stack_a)
{
	int		highest_i;
	t_stk	*ptr;

	if (sort_check(*stack_a))
		return ;
	highest_i = (*stack_a)->index;
	ptr = (*stack_a)->next;
	while (ptr)
	{
		if (ptr->index > highest_i)
			highest_i = ptr->index;
		ptr = ptr->next;
	}
	if ((*stack_a)->index == highest_i)
	{
		rotate(stack_a);
		ft_putstr("ra\n");
	}
	else if ((*stack_a)->next->index == highest_i)
	{
		rev_rotate(stack_a);
		ft_putstr("rra\n");
	}
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap(*stack_a);
}

void	reverse_rotate_both_stacks(t_stk **a, t_stk **b,
												int *cost_a, int *cost_b)
{
	while (1)
	{
		if (*cost_a >= 0 || *cost_b >= 0)
			break ;
		(*cost_b)++;
		do_rev_rotate(a, b, cost_a);
	}
}

void	small_pushswap(t_stk **stk_a, t_stk **stack_b, t_var *var)
{
	int	num_pushed;

	num_pushed = 0;
	if (var->sz == 2)
		swap(*stk_a);
	else if (var->sz == 3)
		tiny_sort(stk_a);
	else if (var->sz > 3)
	{
		while (var->sz - num_pushed > 3)
			do_push(stk_a, stack_b, 'b', &num_pushed);
		tiny_sort(stk_a);
	}
}
