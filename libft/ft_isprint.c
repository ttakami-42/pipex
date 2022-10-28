/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:22:47 by ttakami           #+#    #+#             */
/*   Updated: 2022/05/13 15:45:04 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}
/*int main ()
{
	int i = 2;
	char t = 't';
	
	printf("%d", isprint(i));
	printf("%d\n", ft_isprint(i));
	printf("%d", isprint(t));
	printf("%d\n", ft_isprint(t));
}*/