/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:54:45 by ttakami           #+#    #+#             */
/*   Updated: 2022/06/07 18:17:24 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr;

	ptr = dst;
	if (dst == src)
		return (dst);
	while (len-- > 0)
		*ptr++ = *(unsigned char *)src++;
	return (dst);
}
/*int	main ()
{
	char buf[] = "ABCDDEFG";
	char buf2[] = "123456789";
	char buf3[] = "ABCDDEFG";
	char buf4[] = "123456789";
	memcpy(buf, buf2, 3);
	ft_memcpy(buf3, buf4, 3);
	printf("%s\n", buf);
	printf("%s\n", buf3);
}*/