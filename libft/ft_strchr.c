/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:35:59 by ttakami           #+#    #+#             */
/*   Updated: 2022/06/05 00:59:22 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (const char)c)
			return ((char *)str);
		str++;
	}
	if ((const char)c == '\0')
		return ((char *)str);
	return (NULL);
}
/*
int main ()
{
	char	str[] = "abcd";
	char	c = 'b';
	char	*s1;
	char	*s2;

	s1 = strchr(str, c);
	s2 = ft_strchr(str, c);
	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%p\n", s1);
	printf("%p\n", s2);
}*/