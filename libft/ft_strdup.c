/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:42:08 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/07 14:51:25 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s) + 1;
	s2 = (char *)malloc(len * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	ft_memcpy(s2, s, len);
	return (s2);
}
