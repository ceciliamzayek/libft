/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmzayek <cmzayek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:01:14 by cmzayek           #+#    #+#             */
/*   Updated: 2020/12/01 13:25:39 by cmzayek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_prev;
	t_list	*new_lst;
	t_list	*tmp;

	tmp = lst;
	new_head = NULL;
	new_prev = NULL;
	while (tmp)
	{
		new_lst = ft_lstnew(f(tmp->content));
		if (!new_lst->content)
			ft_lstdelone(new_lst, del);
		else
		{
			if (new_prev)
				new_prev->next = new_lst;
			if (!new_head)
				new_head = new_lst;
		}
		tmp = tmp->next;
		new_prev = new_lst;
	}
	return (new_head);
}
