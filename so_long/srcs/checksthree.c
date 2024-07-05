/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksthree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:22:34 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/27 10:22:36 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

char	**copy_map(char **map, int height)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc((height + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (free_map(copy), NULL);
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

void	flood_fill(char **map, int x, int y, t_game *game)
{
	int	height;
	int	width;

	height = get_map_heightt(game->map);
	width = ft_strlen(game->map[0]);
	if (x < 0 || y < 0 || x >= width || y >= height
		|| map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		game->col--;
	if (map[y][x] == 'E')
		game->path.exit_found = 1;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

void	find_positions(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->path.start_x = x;
				game->path.start_y = y;
			}
			else if (game->map[y][x] == 'E')
			{
				game->path.exit_x = x;
				game->path.exit_y = y;
			}
			x++;
		}
		y++;
	}
}

int	col(t_game *game)
{
	int	i;
	int	x;

	i = 0;
	while (game->map[i])
	{
		x = 0;
		while (game->map[i][x])
		{
			if (game->map[i][x] == 'C')
				game->col++;
			x++;
		}
		i++;
	}
	return (game->col);
}

int	check_valid_path(t_game *game)
{
	int		height;
	int		width;
	int		result;
	char	**map_copy;

	col(game);
	if (game->col == 0)
		return (write(2, "no collectibles\n", 16), cleanup(game), 0);
	find_positions(game);
	height = get_map_heightt(game->map);
	width = ft_strlen(game->map[0]);
	map_copy = copy_map(game->map, height);
	if (!map_copy)
		return (write(2, "map_copy fail\n", ft_strlen("map_copy fail\n")), 0);
	flood_fill(map_copy, game->path.start_x, game->path.start_y, game);
	result = (game->col == 0 && game->path.exit_found);
	free_map(map_copy);
	if (result)
		return (1);
	else
		return (write(2, "No valid path\n", ft_strlen("No valid path\n")), 0);
}
