/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:54:28 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/06 17:50:08 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_pow(int base, int exponent)
{
	if (exponent == 0)
		return (1);
	return (base * ft_pow(base, exponent - 1));
}

/* if base is 10 and the value is negative there should be a
	- in front of the string. Otherwise it's unsigned */

/*
@TODO case mit max neg Zahl abfangen
kürzen
 */
char	*ft_itoa(int value)
{
	int		exponent;
	int		i;
	char	*str;
	long	val;

	val = (long)value;
	exponent = 0;
	i = 0;
	if (val < 0)
	{
		val *= -1;
		i++;
	}
	while (ft_pow(10, exponent) <= val)
	{
		printf("%d\n", exponent);
		exponent++;
	}
	exponent--;
	str = (char *)ft_calloc(exponent + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (i > 0)
		str[0] = '-';
	while (exponent >= 0)
	{
		printf("t\n");
		if ((val / ft_pow(10, exponent)) < 10)
			str[i] = '0' + (val / ft_pow(10, exponent));
		else
			str[i] = 'a' - 10 + (val / ft_pow(10, exponent));
		val -= ((val / ft_pow(10, exponent)) * ft_pow(10, exponent));
		exponent--;
		i++;
	}
	return (str);
}

#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(-2147483647));
}
