/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:44:42 by sargevor          #+#    #+#             */
/*   Updated: 2025/06/04 18:13:52 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    va_list	list;
	int		len;

	len = 0;
	va_start(list, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (ft_check(*s))
			{
				len += ft_choose(s++, list);
			}
		}
		if (*s != '%' && *s)
		{
			len += ft_putchar(*s);
			s++;
		}
	}
	va_end(list);
	return (len);

}