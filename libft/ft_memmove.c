/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:46:29 by sargevor          #+#    #+#             */
/*   Updated: 2025/02/03 16:13:24 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d == s && len == 0)
		return (dst);
	if (s < d)
	{
		i = len + 1;
		while (--i > 0)
		{
			d[i - 1] = s[i - 1];
		}
	}
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}
