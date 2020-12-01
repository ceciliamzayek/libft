/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmzayek <cmzayek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:36:09 by cmzayek           #+#    #+#             */
/*   Updated: 2020/11/22 18:31:58 by cmzayek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst || src)
	{
		while (i < n)
		{
			*((unsigned char*)dst + i) = *((unsigned char*)src + i);
			i++;
		}
		return ((void*)dst);
	}
	return (NULL);
}
