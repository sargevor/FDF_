/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:28:43 by sargevor          #+#    #+#             */
/*   Updated: 2025/02/17 18:50:46 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(size_t nbr, char *simb, size_t base)
{
	if (nbr < base)
		return (ft_putchar(simb[nbr]));
	return (ft_putptr(nbr / base, simb, base)
		+ ft_putptr(nbr % base, simb, base));
}
