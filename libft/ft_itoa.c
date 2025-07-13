/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:43:50 by sargevor          #+#    #+#             */
/*   Updated: 2025/02/04 11:13:01 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lenght(int c)
{
	size_t	len;

	len = 0;
	if (c == 0)
		return (1);
	if (c < 0)
	{
		len++;
		c *= -1;
	}
	while (c != 0)
	{
		len++;
		c /= 10;
	}
	return (len);
}

static void	rec(char *str, size_t i, int n)
{
	char	t;

	if (n < 10)
		str[i] = n + '0';
	else
	{
		t = n % 10 + '0';
		rec(str, i - 1, n / 10);
		str[i] = t;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
	{
		len = lenght(n);
		str = (char *)malloc(len + 1);
		if (str == NULL)
			return (NULL);
		str[len] = '\0';
		i = 0;
		if (n < 0)
		{
			str[i] = '-';
			n *= -1;
			i++;
		}
		i = len - 1;
		rec(str, i, n);
		return (str);
	}
}
