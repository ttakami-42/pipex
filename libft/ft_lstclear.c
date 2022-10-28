/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:15:24 by ttakami           #+#    #+#             */
/*   Updated: 2022/10/12 16:15:49 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*target;
	t_list	*next;

	if (!lst)
		return ;
	target = *lst;
	while (target)
	{
		next = target->next;
		ft_lstdelone(target, del);
		target = next;
	}
	*lst = NULL;
}
