/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:23:37 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/17 16:23:39 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	set_positions(t_stk *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos++;
		stack = stack->next;
	}
}

int	find_target_position_part1(t_stk *a, int b_index, int *min_index_diff)
{
	t_stk	*tmp_a;
	int		target_pos;
	int		index_diff;

	tmp_a = a;
	target_pos = 0;
	while (tmp_a)
	{
		index_diff = tmp_a->index - b_index;
		if (index_diff > 0 && index_diff < *min_index_diff)
		{
			*min_index_diff = index_diff;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

int	find_target_position_part2(t_stk *a, int *min_index_diff)
{
	t_stk	*tmp_a;
	int		target_pos;

	target_pos = 0;
	tmp_a = a;
	while (tmp_a)
	{
		if (tmp_a->index < *min_index_diff)
		{
			*min_index_diff = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

int	find_target_position(t_stk *a, t_stk *b, int b_index)
{
	int	min_index_diff;
	int	target_pos;

	min_index_diff = INT_MAX;
	set_positions(a);
	set_positions(b);
	target_pos = find_target_position_part1(a, b_index, &min_index_diff);
	if (min_index_diff == INT_MAX)
		target_pos = find_target_position_part2(a, &min_index_diff);
	return (target_pos);
}

void	find_target_pos(t_stk **a, t_stk **b)
{
	t_stk	*tmp_b;

	tmp_b = *b;
	while (tmp_b)
	{
		tmp_b->target_pos = find_target_position(*a, *b, tmp_b->index);
		tmp_b = tmp_b->next;
	}
}
