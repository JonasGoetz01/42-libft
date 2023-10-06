/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:54:28 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/06 20:11:54 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_pow(int base, int exponent)
{
	int	res;
	int	i;

	res = 1;
	i = 0;
	while (i < exponent)
	{
		res *= base;
		i++;
	}
	return (res);
}

int	count_digits(long long value)
{
	int	count;

	count = 0;
	if (value < 0)
	{
		value *= -1;
		count++;
	}
	if (value == 0)
	{
		return (1);
	}
	while (value > 0)
	{
		value /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int value)
{
	int			exponent;
	int			i;
	char		*str;
	long long	val;
	char		digit;

	val = (long long)value;
	if (val == -2147483648)
		return (ft_strdup("-2147483648"));
	exponent = count_digits(val);
	i = 0;
	str = (char *)ft_calloc(exponent + 2, sizeof(char));
	if (!str)
		return (NULL);
	if (val < 0)
	{
		str[0] = '-';
		val *= -1;
		i++;
	}
	while (exponent > 0)
	{
		exponent--;
		digit = '0' + (val / ft_pow(10, exponent));
		if (!(digit == '0' && i == 1 && str[0] == '-'))
		{
			str[i] = digit;
			i++;
		}
		val %= ft_pow(10, exponent);
	}
	return (str);
}

#include <stdio.h>

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
}
