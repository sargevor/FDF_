/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:40:54 by sargevor          #+#    #+#             */
/*   Updated: 2025/02/03 17:56:58 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d1;
	size_t			i;

	d1 = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (d1[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
