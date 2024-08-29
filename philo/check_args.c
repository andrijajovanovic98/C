/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:32:02 by ajovanov          #+#    #+#             */
/*   Updated: 2024/08/26 18:32:04 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "piloshopers.h"

int	check_range(int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (!in_range(num))
		{
			printf("Out of range\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_number(int argc, char **argv)
{
	int	i;
	int	b;

	b = 1;
	while (b < argc)
	{
		i = 0;
		while (argv[b][i] != 0 || ft_strncmp(argv[b], "", 2) == 0)
		{
			if (!is_number(argv[b][i]) || argv[b][0] == '0')
			{
				if (argv[b][i] == '-' || argv[b][0] == '0')
				{
					printf("Just positiv number characters\n");
					return (1);
				}
				printf("Just numbers\n");
				return (1);
			}
			i++;
		}
		b++;
	}
	return (0);
}

int	check_and_init_args(int argc, char **argv)
{
	(void)argv;
	if (argc < 5)
		return (write(1, "Zu wenig arguments\n", 19), 1);
	if (argc > 6)
		return (write(1, "Too much arguments\n", 19), 1);
	if (check_number(argc, argv) == 1)
		return (1);
	if (check_range(argc, argv) == 1)
		return (1);
	return (0);
}
