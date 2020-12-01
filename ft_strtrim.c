/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmzayek <cmzayek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:25:17 by cmzayek           #+#    #+#             */
/*   Updated: 2020/11/26 16:25:44 by cmzayek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_ischarset(char c, char const *set)
{
	while (*set)
		if (c == *(set++))
			return (1);
	return (0);
}

static	int	ft_countstart(char const *s1, char const *set)
{
	int count;

	count = 0;
	while (*s1 && ft_ischarset(*(s1++), set))
		count++;
	return (count);
}

static	int	ft_countend(char const *s1, char const *set)
{
	int len;
	int count;

	len = ft_strlen(s1);
	count = 0;
	len--;
	while (len > 0 && ft_ischarset(*(s1 + len--), set))
		count++;
	return (count);
}

static	int	ft_totalcount(char const *s1, char const *set, int len)
{
	int count;

	count = 0;
	if (s1 && set)
		count = ft_countstart(s1, set) + ft_countend(s1, set);
	if (count > len)
		count = len;
	return (count);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*new_str;
	int		char_count;

	i = 0;
	len = 0;
	char_count = 0;
	if (s1)
		len = ft_strlen(s1);
	char_count = ft_totalcount(s1, set, len);
	new_str = (char*)malloc(sizeof(char) * ((len - char_count + 1)));
	if (!new_str)
		return (NULL);
	if (s1)
	{
		if (set)
			while (ft_ischarset(*s1, set))
				s1++;
		while (i < (len - char_count))
			*(new_str + i++) = *(s1++);
	}
	*(new_str + i) = '\0';
	return (new_str);
}
