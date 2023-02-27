/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:54:15 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/28 03:17:35 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_ndigit(long num)
{
	unsigned int	count;

	count = 0;
	if (num <= 0)
	{
		num *= -1;
		count += 1;
	}
	while (num >= 1)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	digit;
	long			num;

	num = n;
	digit = ft_count_ndigit(n);
	result = malloc((digit + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[digit] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		result[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		result[digit - 1] = num % 10 + '0';
		num = num / 10;
		digit--;
	}
	return (result);
}
