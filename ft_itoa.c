/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:54:28 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/06 10:57:16 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_pow(int base, int exponent)
{
	if (exponent == 0)
		return (1);
	return (base * ft_pow(base, exponent - 1));
}

#include <stdio.h>

/* if base is 10 and the value is negative there should be a
	- in front of the string. Otherwise it's unsigned */
char	*ft_itoa(int value, char *str, int base)
{
	int	exponent;
	int	i;

	exponent = 0;
	i = 0;
	while (ft_pow(base, exponent) < value)
		exponent++;
	exponent--;
	while (exponent >= 0)
	{
		if ((value / ft_pow(base, exponent)) < 10)
			str[i] = '0' + (value / ft_pow(base, exponent));
		else
			str[i] = 'a' - 10 + (value / ft_pow(base, exponent));
		value -= ((value / ft_pow(base, exponent)) * ft_pow(base, exponent));
		exponent--;
	}
	return (str);
}

int	main(void)
{
	int	number;

	char str[32] = "";
	number = 17;
	printf("%s\n", ft_itoa(number, str, 16));
}

/* 42d -> o

42/8 5 > 0
42/8^2 2 > 0
42/8^3 0 < 0

42/8^2 = 2
42 - 8^2 * 2 = 26

26/8^1 = 3
26-(8^1*3) = 2

2 / 8^0 = 2
2 -(8^0 * 2) = 0 -> finish

=> 220

 */