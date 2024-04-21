/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 08:39:32 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/10 08:55:55 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmedchar;
	int		start;
	int		end;
	size_t	len;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (s1 == 0 || set == 0)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (start < end && ft_strchr(set, s1[end]))
		end--;
	len = end - start + 1;
	trimmedchar = (char *)malloc((len + 1) * sizeof(char));
	if (trimmedchar == 0)
		return (NULL);
	trimmedchar = ft_strncpy(trimmedchar, &s1[start], len);
	trimmedchar[len] = '\0';
	return (trimmedchar);
}
