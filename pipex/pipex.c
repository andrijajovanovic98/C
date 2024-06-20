/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:29:08 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/20 11:22:42 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	check_is_directory(const char *filepath)
{
	int		fd;
	char	buffer[1];

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return ;
	if (read(fd, buffer, 1) == -1)
	{
		close(fd);
		error();
	}
	close(fd);
}

void	initialize_mystr(int ac, char **av, t_struct *mystr)
{
	if (ac != 5)
		msg();
	check_is_directory(av[1]);
	if (pipe(mystr->pipe_fds) < 0)
		error();
	mystr->infile = -1;
	mystr->outfile = -1;
}

void	close_pipes(t_struct *mystr)
{
	close(mystr->pipe_fds[0]);
	close(mystr->pipe_fds[1]);
}

char	*search_path(char **envp, t_struct *mystr)
{
	int		path_found;
	int		i;

	i = 0;
	path_found = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			path_found = 1;
			break ;
		}
		i++;
	}
	if (!path_found)
	{
		error();
		close_pipes(mystr);
		close(mystr->infile);
		close(mystr->outfile);
		exit(1);
	}
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int ac, char **av, char **envp)
{
	t_struct	mystr;

	initialize_mystr(ac, av, &mystr);
	mystr.paths = search_path(envp, &mystr);
	if (mystr.paths == NULL)
		return (0);
	mystr.cmd_paths = ft_split(mystr.paths, ':');
	if (mystr.cmd_paths == NULL)
		return (0);
	mystr.pid1 = fork();
	if (mystr.pid1 == -1)
		error();
	if (mystr.pid1 == 0)
		first_child(mystr, av, envp);
	mystr.pid2 = fork();
	if (mystr.pid2 == -1)
		error();
	if (mystr.pid2 == 0)
		second_child(ac, mystr, av, envp);
	close_pipes(&mystr);
	waitpid(mystr.pid1, NULL, 0);
	waitpid(mystr.pid2, NULL, 0);
	free_parent(&mystr);
	return (0);
}
