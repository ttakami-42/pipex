/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:47:45 by ttakami           #+#    #+#             */
/*   Updated: 2022/08/01 19:51:11 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (!f)
		return (ft_strdup(str));
	result = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (str[i] != '\0')
	{
		result[i] = f(i, str[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
