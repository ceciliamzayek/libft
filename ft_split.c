/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmzayek <cmzayek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:18:03 by cmzayek           #+#    #+#             */
/*   Updated: 2020/11/27 21:37:31 by cmzayek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countwords(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (s[i++] != c)
		count++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static int		ft_wordlen(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

static void		ft_freeall(char **arr, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

static void		ft_createword(char **dest, char const **src, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((*src)[i] && (*src)[i] == c)
		i++;
	while ((*src)[i] && (*src)[i] != c)
	{
		(*dest)[j] = (*src)[i];
		j++;
		i++;
	}
	(*dest)[j] = '\0';
	(*src) = (*src) + i;
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		word_count;
	char	**words;
	int		word_len;

	i = 0;
	word_count = 0;
	if (s)
		word_count = ft_countwords(s, c);
	words = (char**)malloc(sizeof(char*) * (word_count + 1));
	if (!words)
		return (NULL);
	while (i < word_count)
	{
		word_len = ft_wordlen(s, c);
		words[i] = (char*)malloc(sizeof(char) * (word_len + 1));
		if (!words[i])
		{
			ft_freeall(words, i);
			return (NULL);
		}
		ft_createword(&words[i++], &s, c);
	}
	words[i] = NULL;
	return (words);
}
