/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:17:34 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/28 03:17:49 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;
	size_t	n;

	n = num * size;
	if (num == 0 || size == 0)
		n = 1;
	else if (size > SIZE_MAX / num)
		return (NULL);
	p = malloc(n);
	if (!p)
		return (NULL);
	ft_bzero(p, n);
	return (p);
}
