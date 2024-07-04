/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 09:43:29 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/30 09:43:31 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	free_string_array(char **array)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

void	check_is_directory(char *arg)
{
	int		fd;
	char	buffer[1];

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return ;
	if (read(fd, buffer, 1) == -1)
	{
		close(fd);
		perror("Error");
		return ;
	}
	close(fd);
}

void	msg(char *output)
{
	size_t		i;

	i = 0;
	write(2, &output[i], ft_strlen(output));
	exit(1);
}

void	close_pipes(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
}

int	exit_status(t_stk *var)
{
	if (WIFEXITED(var->status1) && WEXITSTATUS(var->status1) != 0)
		exit(WEXITSTATUS(var->status1));
	if (WIFEXITED(var->status2) && WEXITSTATUS(var->status2) != 0)
		exit(WEXITSTATUS(var->status2));
	exit(EXIT_SUCCESS);
}
