/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:28:22 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/19 19:19:07 by ajovanov         ###   ########.fr       */
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

void	cleanup_and_error(t_struct *mystr, int pipe_end)
{
	close(mystr->pipe_fds[pipe_end]);
	free_parent(mystr);
	error();
}

void	cleanup_and_errorch(t_struct *mystr, int pipe_end)
{
	close(mystr->pipe_fds[pipe_end]);
	free_parent(mystr);
	child_free(mystr);
	error();
}

void	first_child(t_struct mystr, char **av, char **envp)
{
	mystr.infile = open(av[1], O_RDONLY, 0777);
	if (mystr.infile < 0)
	{
		free_parent(&mystr);
		close_pipes(&mystr);
		error();
	}
	if (dup2(mystr.pipe_fds[1], 1) == -1)
		error();
	close(mystr.pipe_fds[0]);
	if (dup2(mystr.infile, 0) == -1)
		error();
	close(mystr.infile);
	mystr.cmd_args = ft_split(av[2], ' ');
	if (!mystr.cmd_args)
		cleanup_and_error(&mystr, 1);
	mystr.cmd = get_cmd(mystr.cmd_paths, mystr.cmd_args[0]);
	if (!mystr.cmd || mystr.cmd[0] == '\0')
		cleanup_and_errorch(&mystr, 1);
	close(mystr.pipe_fds[1]);
	execve(mystr.cmd, mystr.cmd_args, envp);
	error();
}

void	second_child(int ac, t_struct mystr, char **av, char **envp)
{
	mystr.outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (mystr.outfile < 0)
	{
		free_parent(&mystr);
		error();
	}
	if (dup2(mystr.pipe_fds[0], 0) == -1)
		error();
	close(mystr.pipe_fds[1]);
	if (dup2(mystr.outfile, 1) == -1)
		error();
	close(mystr.outfile);
	mystr.cmd_args = ft_split(av[3], ' ');
	if (!mystr.cmd_args)
		cleanup_and_error(&mystr, 0);
	mystr.cmd = get_cmd(mystr.cmd_paths, mystr.cmd_args[0]);
	if (!mystr.cmd || mystr.cmd[0] == '\0')
		cleanup_and_errorch(&mystr, 0);
	close(mystr.pipe_fds[0]);
	execve(mystr.cmd, mystr.cmd_args, envp);
	error();
}
