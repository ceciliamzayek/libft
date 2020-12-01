/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmzayek <cmzayek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 09:22:10 by cmzayek           #+#    #+#             */
/*   Updated: 2020/12/01 14:51:42 by cmzayek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	total;

	i = 0;
	sign = 1;
	total = 0;
	while (ft_isspace(*(str + i)))
		i++;
	if (*(str + i) == '-')
		sign *= -1;
	if (*(str + i) == '+' || *(str + i) == '-')
		i++;
	while (ft_isdigit(*(str + i)))
	{
		total = total * 10 + *(str + i) - '0';
		i++;
	}
	return (total * sign);
}
