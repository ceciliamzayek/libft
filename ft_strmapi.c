/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmzayek <cmzayek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:54:19 by cmzayek           #+#    #+#             */
/*   Updated: 2020/11/26 20:03:31 by cmzayek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	len = 0;
	if (s)
		len = ft_strlen(s);
	new_str = (char*)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (s && *(s + i))
	{
		*(new_str + i) = f(i, *(s + i));
		i++;
	}
	*(new_str + i) = '\0';
	return (new_str);
}
