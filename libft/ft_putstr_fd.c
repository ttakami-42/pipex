/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:10:30 by ttakami           #+#    #+#             */
/*   Updated: 2022/06/05 02:54:43 by ttakami          ###   ########.fr       */
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

void	ft_putstr_fd(char *str, int fd)
{
	size_t	str_len;

	if (!str)
		return ;
	while (*str != '\0')
	{
		str_len = ft_strnlen(str, INT_MAX);
		write(fd, str, str_len);
		str += str_len;
	}
}

/*
	size_t	str_len;

	if (!str)
		return ;
	while (*str != '\0')
	{
		str_len = ft_strnlen(str, INT_MAX);
		write(fd, str, str_len);
		str += str_len;
	}
*/
