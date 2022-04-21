/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:39:41 by damarry           #+#    #+#             */
/*   Updated: 2022/03/05 19:28:22 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lol;
	t_list	*get;

	if (!lst)
		return (NULL);
	get = 0;
	while (lst)
	{
		lol = ft_lstnew((*f)(lst -> content));
		if (!lol)
		{
			ft_lstclear(&get, del);
			return (NULL);
		}
		ft_lstadd_back(&get, lol);
		lol = lol -> next;
		lst = lst -> next;
	}
	return (get);
}
