/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:43:22 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/25 18:43:26 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

void	draw_square(t_game *game, void *mlx, void *win, int color)
{
	int	j;

	game->var.i = 0;
	while (game->var.i < game->var.size)
	{
		j = 0;
		while (j < game->var.size)
		{
			mlx_pixel_put(mlx, win, game->var.x + game->var.i,
				game->var.y + j, color);
			j++;
		}
		game->var.i++;
	}
}

void	draw_tile(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window
			(game->mlx, game->win, game->images.wall, x * 60, y * 60);
	else if (game->map[y][x] == 'C')
	{
		mlx_put_image_to_window
			(game->mlx, game->win, game->images.collect, x * 60, y * 60);
		game->collectibles++;
	}
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window
			(game->mlx, game->win, game->images.exit, x * 60, y * 60);
	else
		mlx_put_image_to_window
			(game->mlx, game->win, game->images.boden, x * 60, y * 60);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->collectibles = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->images.player_img, game->player_x * 60, game->player_y * 60);
}
