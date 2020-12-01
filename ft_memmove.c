/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmzayek <cmzayek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:13:20 by cmzayek           #+#    #+#             */
/*   Updated: 2020/11/25 18:01:39 by cmzayek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (src || dst)
	{
		if (dst < src)
		{
			while (i < len)
			{
				((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
				i++;
			}
			return ((void*)dst);
		}
		i = len - 1;
		while (len)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i--;
			len--;
		}
		return ((void*)dst);
	}
	return (NULL);
}
