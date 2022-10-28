/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:40:00 by ttakami           #+#    #+#             */
/*   Updated: 2022/05/23 14:10:15 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*ptr;

	ptr = NULL;
	while (1)
	{
		if (*(str) == (const char)c)
			ptr = str;
		if (*(str) == '\0')
			break ;
		str++;
	}
	return ((char *)ptr);
}
/*
int main ()
{
	char	str[] = "abcd";
	char	c = 'a';
	char	*s1;
	char	*s2;

	s1 = strrchr(str, c);
	s2 = ft_strrchr(str, c);
	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%p\n", s1);
	printf("%p\n", s2);
}*/