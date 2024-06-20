/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:24:26 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/16 11:24:37 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_if(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int	msg(void)
{
	char	*output;
	int		i;

	i = 0;
	output = "invalid number of arguments\n";
	write(2, &output[i], ft_strlen(output));
	exit(1);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_parent(t_struct *mystr)
{
	int	i;

	i = 0;
	if (mystr->infile != -1)
		close(mystr->infile);
	if (mystr->outfile != -1)
		close(mystr->outfile);
	while (mystr->cmd_paths[i])
	{
		free(mystr->cmd_paths[i]);
		i++;
	}
	free(mystr->cmd_paths);
}

void	child_free(t_struct *mystr)
{
	int	i;

	i = 0;
	while (mystr->cmd_args[i])
	{
		free(mystr->cmd_args[i]);
		i++;
	}
	free(mystr->cmd_args);
	free(mystr->cmd);
}
