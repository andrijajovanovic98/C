/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:39:26 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/17 16:40:45 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_NUMBERS 1000

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <aio.h>

typedef struct s_var
{
	int			sz;
	int			size_a;
	int			size_b;
	int			lowest;
	int			cost_a;
	int			cost_b;
	int			i;
	int			j;
	int			total_cost;
	int			lowest_cost;
	int			tsz;
	int			num_pushed;
	int			counter;
	long long	num;
	int			smallest_pos;
	int			pos;
}			t_var;

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}			t_stk;

int			check(char **av, int ac);
t_stk		*initialize_stack(t_stk **b, char **av, t_var *varr, int ac);
void		index_elements(t_stk *stack_a);
int			sort_check(t_stk *stack);
void		tiny_sort(t_stk **stack);
void		sort(t_stk **stack_a, t_stk **stack_b, t_var *var);
void		find_target_pos(t_stk **stack_a, t_stk **stack_b);
void		do_low_cost_move(t_stk **stack_a, t_stk **stack_b);
t_stk		*stack_new(int value);
int			gett_stk_size(t_stk	*stack);
long int	ft_atoi(t_stk **stack_a, char *str);
void		ft_putstr(char *str);
int			abs(int nb);
void		exit_free(t_stk **stack_a, t_stk **stack_b, int mode, char **sp);
void		*ft_memset(void *s, int c, size_t n);
int			dup_check(char **argv);
void		do_push(t_stk **stk_a, t_stk **stk_b, char name, int *cost);
void		do_rotate(t_stk **stack_a, t_stk **stack_b,
				char operation, int *cost);
void		do_rev_rotate(t_stk **stack_a, t_stk **stack_b, int *cost);
void		rotate(t_stk **stack);
void		rev_rotate(t_stk **stack);
void		swap(t_stk *stack);
void		do_rotate_ab(t_stk **a, t_stk **b, int *cost);
void		reverse_rotate_both_stacks(t_stk **a, t_stk **b,
				int *cost_a, int *cost_b);
int			calculate_cost(int pos, int size);
void		set_positions(t_stk *stack);
void		small_pushswap(t_stk **stk_a, t_stk **stack_b, t_var *var);
char		**ft_split(char const *s, char c);
void		*free_splitt(char **split);
void		exit_free_one(t_stk **stack, int mode, char **sp, int argc);

#endif
