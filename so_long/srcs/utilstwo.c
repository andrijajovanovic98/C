/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilstwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:42:34 by ajovanov          #+#    #+#             */
/*   Updated: 2024/06/28 09:42:37 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	if (dest == NULL || src == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strcspn(const char *src, const char *reject)
{
	size_t	i;
	size_t	j;

	if (src == NULL || reject == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (src[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
