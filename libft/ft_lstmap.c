/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:20:06 by ttakami           #+#    #+#             */
/*   Updated: 2022/10/12 16:21:12 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*result;

	if (!lst || !f)
		return (NULL);
	result = ft_lstnew((*f)(lst->content));
	tmp = result;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew((*f)(lst->content));
		if (!tmp->next)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	tmp->next = 0;
	return (result);
}
