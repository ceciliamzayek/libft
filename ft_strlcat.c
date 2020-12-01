/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmzayek <cmzayek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:04:25 by cmzayek           #+#    #+#             */
/*   Updated: 2020/11/21 18:18:01 by cmzayek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t original_size;

	i = 0;
	j = 0;
	original_size = 0;
	if (dstsize > 0)
		original_size = ft_strlen(dst);
	while (i < dstsize && dst[i])
		i++;
	while (src[j] && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[j])
		j++;
	if (original_size < dstsize)
		return (original_size + j);
	return (dstsize + j);
}
