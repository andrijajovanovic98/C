/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:07:30 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/26 14:59:06 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_line(char *str)
{
	char	*linie;
	size_t	i;

	i = 0;
	if (!str || *str == '\0')
		return (NULL);
	i = find_next_line_break(str, i);
	if (i == 0)
		return (NULL);
	linie = (char *)malloc(sizeof(char) * i + 1);
	if (!linie)
		return (NULL);
	i = 0;
	while (*(str + i) && *(str + i) != '\n')
	{
		*(linie + i) = *(str + i);
		i++;
	}
	if (*(str + i) == '\n')
	{
		*(linie + i) = *(str + i);
		i++;
	}
	*(linie + i) = '\0';
	return (linie);
}

char	*create_substring(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str || !*str)
		return (free(str), str = NULL, NULL);
	i = find_next_line_break(str, i);
	if (i == 0)
		return (free(str), str = NULL, NULL);
	new_str = (char *)malloc((ft_strlenn(str) - i) + 1);
	if (!new_str)
		return (free(str), str = NULL, NULL);
	while (*(str + i))
		*(new_str + j++) = *(str + i++);
	*(new_str + j) = '\0';
	if (!*new_str)
		return (free(str), free(new_str), NULL);
	free(str);
	return (new_str);
}

size_t	find_next_line_break(char *str, size_t i)
{
	if (!str || !str[i])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*rua(int fd, char **read_buffer, char *read_content, int *read_bytes)
{
	*read_bytes = read(fd, read_content, BUFFER_SIZE);
	if (*read_bytes == -1)
		return (free(*read_buffer), *read_buffer = NULL, NULL);
	while (*read_bytes > 0)
	{
		*(read_content + *read_bytes) = '\0';
		*read_buffer = ft_strjoin_and_free(*read_buffer, read_content);
		if (!*read_buffer)
			return (NULL);
		if (ft_strchr(*read_buffer, '\n'))
			break ;
		*read_bytes = read(fd, read_content, BUFFER_SIZE);
		if (*read_bytes == -1)
			return (free(*read_buffer), *read_buffer = NULL, NULL);
	}
	return (*read_buffer);
}

char	*get_next_line(int fd, int clean)
{
	char		*read_content;
	int			read_bytes;
	static char	*read_buffer;

	read_bytes = 1;
	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > INT_MAX)
		return (free(read_buffer), read_buffer = NULL, NULL);
	if (clean == 1)
		return (free(read_buffer), NULL);
	read_content = malloc(BUFFER_SIZE + 1);
	if (read_content == NULL)
		return (free_nm(&read_buffer, NULL), NULL);
	read_buffer = rua(fd, &read_buffer, read_content, &read_bytes);
	if (read_buffer == NULL)
		return (free_nm(&read_buffer, &read_content), NULL);
	free(read_content);
	read_content = read_line(read_buffer);
	if (read_content == NULL)
		return (free_nm(&read_content, &read_buffer), NULL);
	read_buffer = create_substring(read_buffer);
	if (read_buffer == NULL)
		return (free_nm(&read_buffer, NULL), read_content);
	return (read_content);
}
