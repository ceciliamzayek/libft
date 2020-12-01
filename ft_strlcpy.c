/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmzayek <cmzayek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:14:37 by cmzayek           #+#    #+#             */
/*   Updated: 2020/11/26 15:08:56 by cmzayek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (src)
	{
		while (dstsize > 1 && *(src + i))
		{
			*(dst + i) = *(src + i);
			dstsize--;
			i++;
		}
		if (dstsize != 0)
			*(dst + i) = '\0';
		return (ft_strlen(src));
	}
	return (0);
}
