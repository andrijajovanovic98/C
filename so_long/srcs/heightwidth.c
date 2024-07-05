/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heightwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:40:18 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/26 09:40:21 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_map_heightt(char **map)
{
	int	height;

	height = 0;
	while (map[height] != NULL)
		height++;
	return (height);
}

int	get_map_width(char *row)
{
	return (ft_strlen(row));
}
