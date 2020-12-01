/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmzayek <cmzayek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:50:16 by cmzayek           #+#    #+#             */
/*   Updated: 2020/11/21 13:53:24 by cmzayek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		while (i < len && haystack[i] && haystack[i] == needle[j])
		{
			i++;
			j++;
			if (!needle[j])
				return ((char *)&haystack[i - j]);
		}
		i = i - j + 1;
		j = 0;
	}
	return (NULL);
}
