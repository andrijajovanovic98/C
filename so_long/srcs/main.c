/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:20:27 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/26 08:20:36 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

int	get_map_widthh(char **map)
{
	if (!map || !map[0])
		return (0);
	return (ft_strlen(map[0]));
}

void	find_player_collectibles(t_game *game)
{
	int	y;
	int	player_found;
	int	x;

	y = 0;
	player_found = 0;
	game->collectibles = 0;
	while (game->map[y] && !player_found)
	{
		x = 0;
		while (game->map[y][x] && !player_found)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				game->map[y][x] = '0';
				player_found = 1;
			}
			x++;
		}
		y++;
	}
}

int	init_game(t_game *game, char *argv)
{
	int	i;
	int	b;

	game->map = load_map(game, argv);
	if (!game->map)
		return (write(2, "map error\n", 10), 1);
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (1);
	game->var.map_height = get_map_heightt(game->map);
	game->var.map_width = get_map_widthh(game->map);
	i = game->var.map_height * 60;
	b = game->var.map_width * 60;
	if (i > 900 || b > 1500)
		return (write(2, "Too big map\n", 12), cleanup(game), 1);
	if (check_valid_path(game) == 0)
		return (cleanup(game), 1);
	if (!load_images(game))
		return (cleanup(game), 1);
	game->win = mlx_new_window(game->mlx, b, i, "so_long");
	find_player_collectibles(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (write(2, "Arg error\n", 10));
	ft_memset(&game, 0, sizeof(t_game));
	if (init_game(&game, argv[1]) == 1)
		return (0);
	mlx_hook(game.win, 17, 0, cleanup, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	draw_map(&game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
