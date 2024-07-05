/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:35:15 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/26 16:35:17 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

int	check_duplicate_characters(char **map, char *str1)
{
	int	start_count;
	int	exit_count;
	int	y;
	int	x;

	start_count = 0;
	exit_count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				start_count++;
			else if (map[y][x] == 'E')
				exit_count++;
			x++;
		}
		y++;
	}
	y = 0;
	if (start_count != 1 || exit_count != 1)
		return (write(2, &str1[y], ft_strlen(str1)), 0);
	return (1);
}

int	check_rectangular_map(char **map, char *str2)
{
	int	width;
	int	y;
	int	x;

	x = 0;
	width = ft_strlen(map[0]);
	y = 1;
	while (map[y])
	{
		if (ft_strlen(map[y]) != width)
			return (write(1, &str2[x], ft_strlen(str2)), 0);
		y++;
	}
	return (1);
}

int	check_surrounded_by_walls(char **map)
{
	int	width;
	int	height;
	int	y;
	int	x;

	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	x = 0;
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			return (write(2, "Wall Error\n", 11), 0);
		x++;
	}
	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (write(2, "Wall Error\n", 11), 0);
		y++;
	}
	return (1);
}

int	validate_map(t_game *game, char **map)
{
	char	*str1;
	char	*str2;

	game->path.exit_x = 1;
	str1 = "Duplicate characters!\n";
	str2 = "Not rectangular\n";
	if (!valid_chars(map))
		return (0);
	if (!check_duplicate_characters(map, str1))
		return (0);
	if (!check_rectangular_map(map, str2))
		return (0);
	if (!check_surrounded_by_walls(map))
		return (0);
	return (1);
}
