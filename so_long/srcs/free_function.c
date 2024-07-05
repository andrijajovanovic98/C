/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:12:24 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/25 19:12:27 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

void	free_mlx(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_images(t_game *game)
{
	if (game->images.player_img)
		mlx_destroy_image(game->mlx, game->images.player_img);
	if (game->images.wall)
		mlx_destroy_image(game->mlx, game->images.wall);
	if (game->images.boden)
		mlx_destroy_image(game->mlx, game->images.boden);
	if (game->images.collect)
		mlx_destroy_image(game->mlx, game->images.collect);
	if (game->images.exit)
		mlx_destroy_image(game->mlx, game->images.exit);
	if (game->images.won)
		mlx_destroy_image(game->mlx, game->images.won);
}

int	cleanup(t_game *game)
{
	free_images(game);
	free_map(game->map);
	free_mlx(game);
	exit(0);
	return (0);
}
