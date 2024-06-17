/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:28:22 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/15 13:28:44 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		if (!tmp)
			return (NULL);
		command = ft_strjoin(tmp, cmd);
		free_if(&tmp);
		if (command == NULL)
			return (NULL);
		if (access(command, X_OK) == 0)
			return (command);
		free_if(&command);
		paths++;
	}
	return (NULL);
}

void	first_child(t_struct mystr, char **av, char **envp)
{
	dup2(mystr.pipe_fds[1], 1);
	close(mystr.pipe_fds[0]);
	dup2(mystr.infile, 0);
	close(mystr.infile);
	close(mystr.outfile);
	mystr.cmd_args = ft_split(av[2], ' ');
	mystr.cmd = get_cmd(mystr.cmd_paths, mystr.cmd_args[0]);
	if (!mystr.cmd)
	{
		close(mystr.pipe_fds[1]);
		free_parent(&mystr);
		child_free(&mystr);
		error();
		exit(1);
	}
	close(mystr.pipe_fds[1]);
	execve(mystr.cmd, mystr.cmd_args, envp);
	error();
	exit(1);
}

void	second_child(t_struct mystr, char **av, char **envp)
{
	dup2(mystr.pipe_fds[0], 0);
	close(mystr.pipe_fds[1]);
	dup2(mystr.outfile, 1);
	close(mystr.infile);
	close(mystr.outfile);
	mystr.cmd_args = ft_split(av[3], ' ');
	mystr.cmd = get_cmd(mystr.cmd_paths, mystr.cmd_args[0]);
	if (!mystr.cmd)
	{
		close(mystr.pipe_fds[0]);
		free_parent(&mystr);
		child_free(&mystr);
		error();
		exit(1);
	}
	close(mystr.pipe_fds[0]);
	execve(mystr.cmd, mystr.cmd_args, envp);
	error();
	exit(1);
}
