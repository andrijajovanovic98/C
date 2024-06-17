/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:29:57 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/15 13:30:30 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_mystr
{
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
	pid_t	pid1;
	pid_t	pid2;
	int		pipe_fds[2];
	int		infile;
	int		outfile;
}	t_struct;

char	**ft_split(char *s, char c);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
void	first_child(t_struct mystr, char *argv[], char *envp[]);
void	second_child(t_struct mystr, char *argv[], char *envp[]);
void	free_parent(t_struct *mystr);
void	child_free(t_struct *mystr);
int		msg(void);
void	error(void);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	free_if(char **ptr);

#endif
