/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmzayek <cmzayek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:10:28 by cmzayek           #+#    #+#             */
/*   Updated: 2020/11/26 15:24:40 by cmzayek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	len = 0;
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	new_str = (char*)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (s1 && *s1)
		*(new_str + i++) = *(s1++);
	while (s2 && *s2)
		*(new_str + i++) = *(s2++);
	*(new_str + i) = '\0';
	return (new_str);
}
