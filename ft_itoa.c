/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:54:28 by jgotz             #+#    #+#             */
/*   Updated: 2023/10/06 09:09:11 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* if base is 10 and the value is negative there should be a
	- in front of the string. Otherwise it's unsigned */
char	*ft_itoa(int value, char *str, int base)
{
}

/*

string	ans = "";

	while (n != 0) {
		// remainder variable to store remainder
		int rem = 0;

		// ch variable to store each character
		char ch;
		// storing remainder in rem variable.
		rem = n % 16;

		// check if temp < 10
		if (rem < 10) {
			ch = rem + 48;
		}
		else {
			ch = rem + 55;
		}

		// updating the ans string with the character variable
		ans += ch;
		n = n / 16;
	}

	// reversing the ans string to get the final result
	int i = 0, j = ans.size() - 1;
	while(i <= j)
	{
		swap(ans[i], ans[j]);
		i++;
		j--;
	}
	return (ans);

 */

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