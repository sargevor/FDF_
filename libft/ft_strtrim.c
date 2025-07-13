/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:08:37 by sargevor          #+#    #+#             */
/*   Updated: 2025/02/03 21:49:04 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	try(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!set || !s1)
		return (NULL);
	start = 0;
	while (s1[start] && try(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && try(set, s1[end - 1]))
		end--;
	len = end - start;
	new = (char *)malloc(len + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1 + start, len + 1);
	return (new);
}
