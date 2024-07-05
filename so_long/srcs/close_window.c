/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:39:27 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/25 18:39:29 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	can_move_to(t_game *game, int new_x, int new_y)
{
	game->var.map_height = get_map_heightt(game->map);
	if (new_y < 0 || new_y >= game->var.map_height)
		return (0);
	game->var.map_width = get_map_width(game->map[new_y]);
	if (new_x < 0 || new_x >= game->var.map_width)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	else if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles--;
		game->map[new_y][new_x] = '0';
	}
	else if (game->collectibles == 0 && game->map[new_y][new_x] == 'E')
	{
		write(1, "You win!\n", ft_strlen("You win!\n"));
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx, game->win, game->images.won, 35, 40);
		mlx_do_sync(game->mlx);
		cleanup(game);
	}
	return (1);
}

void	handle_keywasd(int keysym, t_game *game)
{
	if (keysym == KEY_W)
	{
		game->var.new_y--;
		if (can_move_to(game, game->var.new_x, game->var.new_y))
			game->player_y--;
	}
	else if (keysym == KEY_A)
	{
		game->var.new_x--;
		if (can_move_to(game, game->var.new_x, game->var.new_y))
			game->player_x--;
	}
	else if (keysym == KEY_S)
	{
		game->var.new_y++;
		if (can_move_to(game, game->var.new_x, game->var.new_y))
			game->player_y++;
	}
	else if (keysym == KEY_D)
	{
		game->var.new_x++;
		if (can_move_to(game, game->var.new_x, game->var.new_y))
			game->player_x++;
	}
}

int	handle_keypress(int keysym, t_game *game)
{
	int		i;
	char	*str;

	i = 0;
	game->prev_x = game->player_x;
	game->prev_y = game->player_y;
	game->var.new_x = game->player_x;
	game->var.new_y = game->player_y;
	handle_keywasd(keysym, game);
	if (keysym == ESC_KEY)
		cleanup(game);
	if (game->player_x != game->prev_x || game->player_y != game->prev_y)
	{
		game->steps++;
		str = ft_itoa(game->steps);
		write(1, str, ft_strlen(str));
		free(str);
		write(1, "\n", 1);
	}
	draw_map(game);
	return (0);
}
