/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:13:44 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/28 03:15:32 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_move_splitstart(char const *str, char c)
{
	size_t	count;

	count = 0;
	while (str[count] && str[count] == c)
		count++;
	return (count);
}

static size_t	ft_get_splitlen(char const *str, char c)
{
	size_t	count;

	count = 0;
	while (str[count] && str[count] != c)
		count++;
	return (count);
}

static size_t	ft_get_splittimes(char const *str, char c)
{
	size_t	elem;

	elem = 0;
	while (*str != '\0')
	{
		str += ft_move_splitstart(str, c);
		if (*str == '\0')
			break ;
		str += ft_get_splitlen(str, c);
		elem++;
	}
	return (elem);
}

static void	*ft_free_array(char **result)
{
	size_t	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	size_t	split_len;
	size_t	split_count;
	size_t	result_i;

	if (!str)
		return (NULL);
	split_count = ft_get_splittimes(str, c);
	result = malloc(sizeof(char *) * (split_count + 1));
	if (!result)
		return (NULL);
	result_i = 0;
	while (result_i < split_count)
	{
		str += ft_move_splitstart(str, c);
		split_len = ft_get_splitlen(str, c);
		result[result_i] = ft_substr(str, 0, split_len);
		if (!result[result_i])
			return (ft_free_array(result));
		str += split_len;
		result_i++;
	}
	result[result_i] = NULL;
	return (result);
}
