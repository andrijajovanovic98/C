/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:23:57 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/11 14:38:59 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_copytwo(char *des, char *sr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		des[i] = sr[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*des;
	char	*sr;

	des = (char *)dest;
	sr = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (des > sr)
	{
		i = n;
		while (i > 0)
		{
			--i;
			des[i] = sr[i];
		}
	}
	else
		ft_copytwo(des, sr, n);
	return (dest);
}
