/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:07:14 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/08 16:46:23 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	int		i;
	int		b;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	newstring = (char *)malloc(len + 1 * sizeof(char));
	if (newstring == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		newstring[i] = s1[i];
		i++;
	}
	b = 0;
	while (s2[b])
	{
		newstring[i + b] = s2[b];
		b++;
	}
	newstring[i + b] = '\0';
	return (newstring);
}
