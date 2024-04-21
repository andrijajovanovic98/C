/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:05:00 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/10 17:14:08 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = 0;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	if (s == 0)
		return ((char *)s);
	while (s[i])
	{
		if (s[i] == (char)c)
			ret = (char *)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		ret = (char *)&s[i];
	return (ret);
}
