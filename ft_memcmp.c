/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmzayek <cmzayek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:33:49 by cmzayek           #+#    #+#             */
/*   Updated: 2020/11/25 17:53:10 by cmzayek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*uc_s1;
	const unsigned char	*uc_s2;

	uc_s1 = (unsigned char*)s1;
	uc_s2 = (unsigned char*)s2;
	while (n-- > 0)
		if (*uc_s1++ != *uc_s2++)
			return ((int)(*--uc_s1 - *--uc_s2));
	return (0);
}
