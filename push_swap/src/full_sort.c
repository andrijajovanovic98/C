/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:29:38 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/17 16:31:10 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	move_smallest_on_the_top(t_stk **stack_a)
{
	int		total_size;
	t_stk	*tmp;
	t_var	var;
	int		lowest_index;

	tmp = *stack_a;
	total_size = gett_stk_size(*stack_a);
	lowest_index = INT_MAX;
	ft_memset(&var, 0, sizeof(t_var));
	while (tmp)
	{
		tmp->pos = var.pos++;
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			var.smallest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (var.smallest_pos > total_size / 2)
		while (var.smallest_pos < total_size)
			do_rev_rotate(stack_a, NULL, &var.smallest_pos);
	else
		while (var.smallest_pos > 0)
			do_rotate(stack_a, NULL, 'a', &var.smallest_pos);
}

void	sort(t_stk **stack_a, t_stk **stack_b, t_var *var)
{
	int		size_a;
	int		size_b;
	t_stk	*temp_b;

	if (sort_check(*stack_a) == 1)
		exit_free(stack_a, NULL, 1, NULL);
	small_pushswap(stack_a, stack_b, var);
	while (*stack_b)
	{
		size_a = gett_stk_size(*stack_a);
		size_b = gett_stk_size(*stack_b);
		find_target_pos(stack_a, stack_b);
		temp_b = *stack_b;
		while (temp_b)
		{
			temp_b->cost_b = calculate_cost(temp_b->pos, size_b);
			temp_b->cost_a = calculate_cost(temp_b->target_pos, size_a);
			temp_b = temp_b->next;
		}
		do_low_cost_move(stack_a, stack_b);
	}
	if (sort_check(*stack_a) == 0)
		move_smallest_on_the_top(stack_a);
}

void	swap(t_stk *stack)
{
	int	temp_value;
	int	temp_index;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp_value = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp_value;
	temp_index = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp_index;
	ft_putstr("sa\n");
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != 0) && (s2[i] != 0) && (s1[i] == s2[i]))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	dup_check(char **argv)
{
	int	i;
	int	b;

	i = 0;
	while (argv[i] != NULL)
	{
		b = i + 1;
		while (argv[b] != NULL)
		{
			if (ft_strcmp(argv[i], argv[b]) == 0)
				return (1);
			b++;
		}
		if (argv[i][0] == '0' && argv[i][1] != '\0')
			return (1);
		i++;
	}
	return (0);
}
