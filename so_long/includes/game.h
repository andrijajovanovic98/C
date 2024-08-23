/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:49:06 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/26 08:49:09 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define ESC_KEY 65307 // ESC
# define KEY_W 119 // 'w'
# define KEY_A 97  // 'a' 
# define KEY_S 115 // 's' 
# define KEY_D 100 // 'd' 

# include "mlx.h"
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include "get_next_line.h"

typedef struct s_path
{
	int	start_x;
	int	start_y;
	int	exit_x;
	int	exit_y;
	int	height;
	int	width;
	int	exit_found;
}	t_path;

typedef struct s_variables
{
	int	map_height;
	int	new_x;
	int	new_y;
	int	map_width;
	int	i;
	int	j;
	int	size;
	int	x;
	int	y;
}	t_variables;

typedef struct s_images
{
	void	*player_img;
	void	*wall;
	void	*boden;
	void	*collect;
	void	*exit;
	void	*won;
	char	*player_img_path;
	char	*wall_img_path;
	char	*boden_img_path;
	char	*collect_img_path;
	char	*exit_img_path;
	char	*won_img_path;
}	t_images;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			player_x;
	int			player_y;
	int			collectibles;
	int			steps;
	char		*str;
	int			col;
	int			prev_x;
	int			prev_y;
	t_images	images;
	t_variables	var;
	t_path		path;
}	t_game;

int		get_map_height(const char *file_path);
int		get_map_heightt(char **map);
int		get_map_width(char *row);
char	**load_map(t_game *game, const char *file_path);
void	draw_map(t_game *game);
int		handle_keypress(int keysym, t_game *game);
int		load_images(t_game *game);
int		cleanup(t_game *game);
void	free_map(char **map);
int		ft_strlen(char *str);
int		validate_map(t_game *game, char **map);
int		valid_chars(char **map);
int		check_valid_path(t_game *game);
int		close_window(void *param);
char	*ft_itoa(int n);
char	*ft_strdup(char *s);
char	*ft_strcpy(char *dest, const char *src);
size_t	ft_strcspn(const char *src, const char *reject);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif
