/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:54:13 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/26 14:55:01 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

size_t	ft_strlenn(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_and_free(char *s1, char *s2);
char	*read_line(char *str);
char	*create_substring(char *str);
char	*get_next_line(int fd, int clean);
size_t	find_next_line_break(char *str, size_t i);
char	*rua(int fd, char **read_buffer, char *read_content, int *read_bytes);
void	*free_nm(char **buff1, char **buff2);
void	*ft_memset(void *s, int c, size_t n);

#endif
