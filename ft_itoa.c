/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmzayek <cmzayek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:53:36 by cmzayek           #+#    #+#             */
/*   Updated: 2020/11/28 13:21:42 by cmzayek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calclen(int n)
{
	int count;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while ((n /= 10) != 0)
		count++;
	return (count);
}

static void	ft_filldigits(char *result, int n, int word_len)
{
	int i;
	int is_neg;

	i = 0;
	is_neg = 0;
	if (n < 0)
	{
		result[i++] = '-';
		if (n == INT_MIN)
		{
			result[word_len - i++] = (n % 10 * -1) + '0';
			n /= 10;
		}
		n *= -1;
		is_neg++;
	}
	while (i < word_len)
	{
		result[word_len - i++ - 1 + is_neg] = n % 10 + '0';
		n /= 10;
	}
	result[i] = '\0';
}

char		*ft_itoa(int n)
{
	int		word_len;
	char	*result;

	word_len = ft_calclen(n);
	result = (char*)malloc(sizeof(char) * (word_len + 1));
	if (!result)
		return (NULL);
	ft_filldigits(result, n, word_len);
	return (result);
}
