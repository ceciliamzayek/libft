/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmzayek <cmzayek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:55:17 by cmzayek           #+#    #+#             */
/*   Updated: 2020/12/01 14:47:36 by cmzayek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	tmp = *lst;
	if (tmp->next)
		ft_lstclear(&(tmp->next), del);
	del(tmp->content);
	free(tmp);
	*lst = NULL;
}
