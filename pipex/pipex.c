/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 09:50:05 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/30 09:50:09 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*find_path(char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			return (*env + 5);
		env++;
	}
	return (NULL);
}

char	*find_command(t_stk var, char *cmd_args, char **env)
{
	var.i = 0;
	var.path_env = find_path(env);
	if (!var.path_env)
		return (write(2, "Path error\n", 11), NULL);
	var.path_dirs = ft_split(var.path_env, ':');
	if (!var.path_dirs)
		return (NULL);
	while (var.path_dirs[var.i])
	{
		var.command_path = ft_strjoin(var.path_dirs[var.i], cmd_args);
		if (access(var.command_path, X_OK) == 0)
		{
			free_string_array(var.path_dirs);
			return (var.command_path);
		}
		free(var.command_path);
		var.i++;
	}
	free_string_array(var.path_dirs);
	write(2, "Command not found\n", 18);
	return (NULL);
}

void	child(int *pipefd, t_stk var, char **av, char **env)
{
	var.infile = open(av[1], O_RDONLY, 0777);
	if (var.infile == -1)
		close_fds_and_exit(pipefd, -1, -1, "open infile");
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		close_fds_and_exit(pipefd, -1, var.infile, "dup2 pipefd[1]");
	close(pipefd[1]);
	close(pipefd[0]);
	if (dup2(var.infile, STDIN_FILENO) == -1)
		close_fds_and_exit(NULL, -1, -1, "dup2 var.infile");
	close(var.infile);
	var.cmd_args = ft_split(av[2], ' ');
	if (!var.cmd_args)
		msg("Command not found\n");
	if (access(av[2], X_OK) == 0)
		execve(av[2], var.cmd_args, env);
	var.cmd = find_command(var, var.cmd_args[0], env);
	if (!var.cmd)
	{
		free_string_array(var.cmd_args);
		exit(EXIT_FAILURE);
	}
	execve(var.cmd, var.cmd_args, env);
	free_string_array(var.cmd_args);
	free(var.cmd);
	msg("Execve error\n");
}

void	childtwo(int *pipefd, t_stk var, char **av, char **env)
{
	var.outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (var.outfile == -1)
		close_fds_and_exit(pipefd, -1, -1, "openoutfile");
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		close_fds_and_exit(pipefd, pipefd[0], pipefd[1], "dup2 pipefd[0]");
	close(pipefd[0]);
	close(pipefd[1]);
	if (dup2(var.outfile, STDOUT_FILENO) == -1)
		close_fds_and_exit(NULL, -1, -1, "dup2 var.outfile");
	close(var.outfile);
	var.cmd_args = ft_split(av[3], ' ');
	if (!var.cmd_args)
		msg("Command not found");
	if (access(av[3], X_OK) == 0)
		execve(av[3], var.cmd_args, env);
	var.cmd = find_command(var, var.cmd_args[0], env);
	if (!var.cmd)
	{
		free_string_array(var.cmd_args);
		exit(1);
	}
	execve(var.cmd, var.cmd_args, env);
	free_string_array(var.cmd_args);
	free(var.cmd);
	msg("Execve error\n");
}

int	main(int argc, char **argv, char **env)
{
	t_stk	var;
	int		pipefd[2];

	ft_memset(&var, -1, sizeof(t_stk));
	if (argc != 5)
		msg("Invalide numbser of arguments\n");
	check_is_directory(argv[1]);
	if (pipe(pipefd) < 0)
		msg("Pipe error\n");
	var.pid1 = fork();
	if (var.pid1 == -1)
		msg("Fork error\n");
	if (var.pid1 == 0)
		child(pipefd, var, argv, env);
	var.pid2 = fork();
	if (var.pid2 == -1)
		msg("Fork error\n");
	if (var.pid2 == 0)
		childtwo(pipefd, var, argv, env);
	close_pipes(pipefd);
	waitpid(var.pid1, &var.status1, 0);
	waitpid(var.pid2, &var.status2, 0);
	exit_status(&var);
	return (0);
}
