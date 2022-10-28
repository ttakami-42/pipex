/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:55:30 by ttakami           #+#    #+#             */
/*   Updated: 2022/06/06 12:29:31 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_get_toptriml(char const *s1, char const *set)
{
	size_t	count;

	count = 0;
	while (s1[count] && ft_strchr(set, s1[count]) != NULL)
		count++;
	if (s1[count] == '\0')
		return (0);
	return (count);
}

static	size_t	ft_get_bottomtriml(char const *s1, char const *set)
{
	size_t	count;

	count = 0;
	while (s1[count] != '\0')
		count++;
	while (count != 0 && ft_strchr(set, s1[count - 1]) != NULL)
		count--;
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start_i;

	if (!s1 || !set)
		return (NULL);
	start_i = ft_get_toptriml(s1, set);
	result = ft_substr(s1, start_i, ft_get_bottomtriml(s1, set) - start_i);
	return (result);
}
