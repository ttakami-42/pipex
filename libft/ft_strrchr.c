/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:40:00 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/28 03:19:32 by ttakami          ###   ########.fr       */
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
