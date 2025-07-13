/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:54:19 by sargevor          #+#    #+#             */
/*   Updated: 2025/02/02 21:13:53 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;
	size_t	i;

	i = 0;
	a = ft_strlen(dst);
	b = ft_strlen(src);
	if (dstsize <= a)
		return (dstsize + b);
	else
	{
		while (a + i < dstsize - 1 && src[i] != '\0')
		{
			dst[a + i] = src [i];
			i++;
		}
		dst[a + i] = '\0';
		return (a + b);
	}
}
