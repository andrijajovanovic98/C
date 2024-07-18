/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:27:58 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/17 16:29:05 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	sort_check(t_stk *stk)
{
	t_stk	*current;

	current = stk;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	check(char **av, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j])
		{
			if (!((av[i][j] >= '0' && av[i][j] <= '9') ||
			av[i][j] == '-' || av[i][j] == '+'))
				exit_free_one(NULL, 0, av, ac);
			j++;
		}
		i++;
	}
	if (dup_check(av) == 1)
		exit_free_one(NULL, 0, av, ac);
	return (0);
}

void	do_rev_rotate(t_stk **stack_a, t_stk **stack_b, int *cost)
{
	if (stack_b == NULL)
	{
		rev_rotate(stack_a);
		ft_putstr("rra\n");
		(*cost)++;
	}
	if (stack_a == NULL)
	{
		rev_rotate(stack_b);
		ft_putstr("rrb\n");
		(*cost)++;
	}
	if (stack_a != NULL && stack_b != NULL)
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
		ft_putstr("rrr\n");
		(*cost)++;
	}
}

void	rev_rotate(t_stk **stack)
{
	t_stk	*last_element;
	t_stk	*second_last;
	t_stk	*current;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;
	while (current->next != NULL)
	{
		second_last = current;
		current = current->next;
	}
	last_element = current;
	if (second_last != NULL)
	{
		second_last->next = NULL;
		last_element->next = *stack;
		*stack = last_element;
	}
}

int	main(int argc, char **argv)
{
	t_stk	*stk_a;
	t_stk	*stk_b;
	t_var	var;
	char	**args;

	if (argc < 2)
		exit (0);
	else if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			exit_free(NULL, NULL, 0, args);
	}
	else
		args = argv + 1;
	ft_memset(&var, 0, sizeof(t_var));
	check(args, argc);
	stk_a = initialize_stack(&stk_b, args, &var, argc);
	if (stk_a == NULL)
		return (1);
	if (argc == 2)
		free_splitt(args);
	sort(&stk_a, &stk_b, &var);
	exit_free(&stk_a, &stk_b, 2, NULL);
	return (0);
}
