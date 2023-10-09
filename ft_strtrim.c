/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:54:28 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/09 16:17:27 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_trimmed_str_len(const char *s1, const char *set)
{
	size_t	trimmed_len;
	size_t	i;

	i = 0;
	trimmed_len = ft_strlen(s1);
	while (i < ft_strlen(set) && (ft_strchr(set, s1[i]) != NULL))
	{
		trimmed_len--;
		i++;
	}
	i = 0;
	while (i < ft_strlen(set) && (ft_strchr(set, s1[ft_strlen(s1) - 1
				- i]) != NULL))
	{
		trimmed_len--;
		i++;
	}
	return (trimmed_len);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)malloc((get_trimmed_str_len(s1, set) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (ft_strchr(set, s1[i]) != NULL && i < ft_strlen(s1))
		i++;
	ft_strlcpy(res, &s1[i], get_trimmed_str_len(s1, set) + 1);
	return (res);
}

/* const char	*end;
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
	return (trimmed_str); */
