/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:37:14 by ttakami           #+#    #+#             */
/*   Updated: 2021/09/09 15:37:14 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	while (len && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		len--;
	}
	if (len == 0)
		return (0);
	else
		return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
