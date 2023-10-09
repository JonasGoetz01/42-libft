/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:54:28 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/09 10:09:28 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		words_count;
	char	**result;
	int		word_len;
	int		i;

	i = 0;
	words_count = count_words(s, c);
	result = (char **)ft_calloc(words_count + 1, sizeof(char *));
	if (!result)
		return (NULL);
	while (i < words_count)
	{
		while (*s && *s == c)
			s++;
		word_len = 0;
		while (*s && *s != c)
		{
			word_len++;
			s++;
		}
		result[i] = ft_substr(s - word_len, 0, word_len);
		if (!result[i])
		{
			while (i >= 0)
				free(result[i--]);
			free(result);
			return (NULL);
		}
		i++;
	}
	return (result);
}
