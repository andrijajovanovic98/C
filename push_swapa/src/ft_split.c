/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:17:19 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/11 11:19:28 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	dup = malloc(n + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	*free_split(char **split, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static int	ft_fill(char **result, const char *s, char c, size_t word_count)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] && j < word_count)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			result[j] = ft_strndup(s + start, i - start);
			if (!result[j++])
			{
				free_split(result, j);
				return (0);
			}
		}
	}
	result[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;

	if (s == NULL)
		return (NULL);
	word_count = ft_count_words(s, c);
	result = malloc((word_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	if (!ft_fill(result, s, c, word_count))
		return (NULL);
	return (result);
}
