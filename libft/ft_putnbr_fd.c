/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:32:35 by ttakami           #+#    #+#             */
/*   Updated: 2022/05/27 14:48:07 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		count;
	long	num;

	num = n;
	count = 1;
	if (n < 0)
	{
		num *= -1;
		write(fd, "-", 1);
	}
	while (n / 10 != 0)
	{
		n /= 10;
		count *= 10;
	}
	while (count > 0)
	{
		c = '0' + (num / count);
		write(fd, &c, 1);
		num -= (num / count) * count;
		count /= 10;
	}
}
