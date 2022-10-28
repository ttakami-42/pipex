/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 23:07:24 by ttakami           #+#    #+#             */
/*   Updated: 2022/06/07 18:16:25 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (d == s)
		return (dst);
	if (d < s)
		return (ft_memcpy(d, s, len));
	else
	{
		while (len > 0)
		{
			*(d + (len - 1)) = *(unsigned char *)(s + (len - 1));
			len--;
		}
	}
	return (dst);
}
