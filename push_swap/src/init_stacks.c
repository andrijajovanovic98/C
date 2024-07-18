/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:22:37 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/17 16:38:43 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stk	*initialize_stack(t_stk **b, char **av, t_var *varr, int ac)
{
	t_stk		*stack_a;
	t_stk		*new_node;
	t_var		var;
	t_stk		**last_ptr;

	last_ptr = &stack_a;
	stack_a = NULL;
	var.num = 0;
	var.i = 0;
	*b = NULL;
	while (av[var.i] != NULL)
	{
		var.num = ft_atoi(&stack_a, av[var.i]);
		if (var.num > INT_MAX || var.num < INT_MIN)
			exit_free_one(&stack_a, 0, av, ac);
		new_node = stack_new((int)var.num);
		if (!new_node)
			exit_free_one(&stack_a, 0, av, ac);
		*last_ptr = new_node;
		last_ptr = &new_node->next;
		var.i++;
	}
	index_elements(stack_a);
	varr->sz = gett_stk_size(stack_a);
	return (stack_a);
}

void	index_elements(t_stk *stack_a)
{
	t_stk	*ptr;
	t_stk	*smallest;
	int		stack_size;
	int		current_index;

	current_index = 1;
	stack_size = gett_stk_size(stack_a);
	while (current_index <= stack_size)
	{
		ptr = stack_a;
		smallest = NULL;
		while (ptr)
		{
			if ((ptr->index == 0)
				&& (!smallest || ptr->value < smallest->value))
				smallest = ptr;
			ptr = ptr->next;
		}
		if (smallest)
		{
			smallest->index = current_index;
			current_index++;
		}
	}
}

t_stk	*stack_new(int value)
{
	t_stk	*new_node;

	new_node = malloc(sizeof(t_stk));
	if (!new_node)
		return (NULL);
	ft_memset(new_node, -1, sizeof(t_stk));
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

int	gett_stk_size(t_stk	*stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	*free_splitt(char **split)
{
	size_t	i;

	i = 0;
	if (split == NULL)
		return (NULL);
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}
