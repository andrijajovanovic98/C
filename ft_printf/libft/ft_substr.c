/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 10:49:42 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/08 13:58:40 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	sleng;
	size_t	i;

	if (s == NULL)
		return (NULL);
	sleng = ft_strlen(s);
	if (start >= sleng || s == 0)
	{
		substr = (char *)malloc(1 * sizeof(char));
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (start + len > sleng)
		len = sleng - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while ((i < len) && (s[start] != '\0'))
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
