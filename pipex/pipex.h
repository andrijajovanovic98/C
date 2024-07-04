/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:57:59 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/30 16:58:01 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_stk
{
	int		i;
	int		status1;
	int		status2;
	char	*path_env;
	char	**path_dirs;
	char	*command_path;
	char	*cmd;
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	char	**cmd_args;
}	t_stk;

char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memset(void *s, int c, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
void	close_fds_and_exit(int *pipefd, int fd1, int fd2, char *msg);
void	free_string_array(char **array);
void	check_is_directory(char *arg);
size_t	ft_strlen(const char *s);
void	msg(char *output);
void	close_pipes(int *pipefd);
int		exit_status(t_stk *var);

#endif
