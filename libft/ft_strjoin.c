/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 07:24:32 by ttakami           #+#    #+#             */
/*   Updated: 2022/08/01 19:50:58 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_size;
	size_t	s2_size;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	result = malloc((s1_size + s2_size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy((result + ft_strlcpy(result, s1, s1_size + 1)), s2, s2_size + 1);
	return (result);
}
