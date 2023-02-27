/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:47:44 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/28 03:16:00 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	size;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	if (size <= start)
		size = 0;
	else
	{
		size = size - start;
		if (size > len)
			size = len;
	}
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, str + start, size);
	*(result + size) = '\0';
	return (result);
}
