/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:00:37 by sargevor          #+#    #+#             */
/*   Updated: 2025/02/06 18:09:19 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	dif;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	dif = s_len - start;
	if (dif > len)
		dif = len;
	res = (char *)malloc(dif + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s + start, dif + 1);
	res[dif] = '\0';
	return (res);
}
