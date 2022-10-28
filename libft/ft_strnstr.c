/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 01:15:24 by ttakami           #+#    #+#             */
/*   Updated: 2022/05/03 01:15:24 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	j = 0;
	while (j < len && haystack[j])
	{
		i = 0;
		while (j < len && needle[i] && haystack[j] && needle[i] == haystack[j])
		{
			++i;
			++j;
		}
		if (needle[i] == '\0')
			return ((char *)&haystack[j - i]);
		j = j - i + 1;
	}
	return (0);
}
/*
int main () {
	char str1[] = "abcdefghijk";
	char str2[] = "ghi";
	char str3[] = "abcdefghijk";
	char str4[] = "ghi";
	char *s;
	char *ss;
	s = strnstr(str1, str2, 20);
	ss = ft_strnstr(str3, str4, 20);
	printf("%s\n", str1);
	printf("%s\n", s);
	printf("%s\n", str3);
	printf("%s\n", ss);
}*/