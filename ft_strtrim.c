/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:54:28 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/09 00:56:17 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*end;
	size_t		trimmed_len;
	char		*trimmed_str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strnstr(set, s1, 1) != NULL)
		s1++;
	end = s1 + ft_strlen(s1) - 1;
	while (end > s1 && ft_strnstr(set, end, 1) != NULL)
		end--;
	trimmed_len = end - s1 + 1;
	trimmed_str = (char *)malloc(trimmed_len + 1);
	if (trimmed_str == NULL)
		return (NULL);
	ft_strlcpy(trimmed_str, s1, trimmed_len + 1);
	return (trimmed_str);
}
