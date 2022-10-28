/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:27:44 by ttakami           #+#    #+#             */
/*   Updated: 2022/08/07 02:47:23 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strnlen(const char *str, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (i < maxlen && str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;

	dst_len = 0;
	if (size != 0)
		dst_len = ft_strnlen(dst, size);
	return (dst_len + ft_strlcpy(dst + dst_len, src, (size - dst_len)));
}
/*
int main(int argc, char *argv[])
{
	(void)argc;

    char dest[11] = "Tokyo";
    char src[] = "Japan";
	int p = ft_strlcat(dest, src, ft_atoi(argv[1]));
    printf("%s\n%d\n", dest, p);

	char dst[11] = "Tokyo";
    char s[] = "Japan";
	int r = strlcat(dst, s, ft_atoi(argv[2]));
	printf("%s\n%d\n", dst, r);
}*/