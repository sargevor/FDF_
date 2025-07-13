/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:07:20 by sargevor          #+#    #+#             */
/*   Updated: 2025/02/02 17:22:41 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*d1;
	unsigned char	*d2;
	size_t			i;	

	i = 0;
	d1 = (unsigned char *) s1;
	d2 = (unsigned char *) s2;
	while (i < n)
	{
		if (d1[i] == d2[i])
			i++;
		else
			return (d1[i] - d2[i]);
	}
	return (0);
}
