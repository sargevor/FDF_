/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:31:53 by sargevor          #+#    #+#             */
/*   Updated: 2025/02/02 20:07:35 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;
	size_t	len;

	i = 0;
	len = count * size;
	mem = (char *)malloc(len);
	if (mem == NULL)
		return (NULL);
	while (i < len)
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)mem);
}
