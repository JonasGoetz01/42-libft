/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:54:28 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/09 23:44:33 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

void	ft_strrev(char *str)
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = ft_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
}

int	get_num_digits(int n)
{
	int	i;
	int	number;

	i = 0;
	number = ft_abs(n);
	if (number == 0)
		return (1);
	while (number > 0)
	{
		number /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		neg;
	size_t	length;

	neg = (n < 0);
	if (n == -2147483648)
	{
		str = ft_calloc(12, sizeof(*str));
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	str = ft_calloc(get_num_digits(n) + 1 + neg, sizeof(*str));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + ft_abs(n % 10);
		n = (n / 10);
	}
	if (neg)
		str[length] = '-';
	ft_strrev(str);
	str[length + 1] = '\0';
	return (str);
}

/* #include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-42));
	printf("%s\n", ft_itoa(42));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-0));
	printf("%s\n", ft_itoa(1));
	printf("%s\n", ft_itoa(-1));
} */
