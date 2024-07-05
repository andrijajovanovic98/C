/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:27:39 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/26 08:27:44 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

void	cleanup_images(t_game *game)
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

int	load_images(t_game *game)
{
	int		width;
	int		height;	

	game->images.player_img_path = "./images/player.xpm";
	game->images.wall_img_path = "./images/wall.xpm";
	game->images.boden_img_path = "./images/boden.xpm";
	game->images.collect_img_path = "./images/collect.xpm";
	game->images.exit_img_path = "./images/exit.xpm";
	game->images.won_img_path = "./images/won.xpm";
	game->images.player_img = mlx_xpm_file_to_image
		(game->mlx, game->images.player_img_path, &width, &height);
	game->images.wall = mlx_xpm_file_to_image
		(game->mlx, game->images.wall_img_path, &width, &height);
	game->images.boden = mlx_xpm_file_to_image
		(game->mlx, game->images.boden_img_path, &width, &height);
	game->images.collect = mlx_xpm_file_to_image
		(game->mlx, game->images.collect_img_path, &width, &height);
	game->images.exit = mlx_xpm_file_to_image
		(game->mlx, game->images.exit_img_path, &width, &height);
	game->images.won = mlx_xpm_file_to_image
		(game->mlx, game->images.won_img_path, &width, &height);
	if (!game->images.player_img || !game->images.wall || !game->images.boden
		|| !game->images.collect || !game->images.exit || !game->images.won)
		return (write(2, "img error\n", 10), cleanup(game), 0);
	return (1);
}
