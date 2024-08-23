/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:55:53 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/26 08:55:57 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"
#include "get_next_line.h"

void	clean_map(char **map, int height, char *line)
{
	int	i;

	if (map)
	{
		i = 0;
		while (i < height && map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	if (line)
		free(line);
}

int	get_map_height(const char *file_path)
{
	int		height;
	char	c;
	int		fd;

	height = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, &c, 1) > 0)
		if (c == '\n')
			height++;
	height++;
	close(fd);
	return (height);
}

char	**allocate_map(int fd, int height)
{
	char	**map;
	int		i;
	char	*line;

	map = ft_calloc((height + 1), sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd, 0);
	while (line != NULL && i < height)
	{
		map[i] = ft_calloc(ft_strlenn(line) + 1, sizeof(char));
		if (!map[i])
			return (clean_map(map, i, line), get_next_line(fd, 1), NULL);
		ft_strcpy(map[i], line);
		map[i][ft_strcspn(map[i], "\n")] = '\0';
		free(line);
		i++;
		line = get_next_line(fd, 0);
	}
	map[height] = NULL;
	return (map);
}

char	**load_map(t_game *game, const char *file_path)
{
	int		height;
	int		fd;
	char	**map;

	height = 0;
	height = get_map_height(file_path);
	if (height <= 0)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = allocate_map(fd, height);
	close(fd);
	if (!map)
		return (NULL);
	if (!validate_map(game, map))
		return (free_map(map), NULL);
	return (map);
}
