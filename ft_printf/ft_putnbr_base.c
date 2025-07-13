/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:27:33 by sargevor          #+#    #+#             */
/*   Updated: 2025/02/17 18:39:27 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *simb, unsigned int base)
{
	if (nbr < base)
		return (ft_putchar(simb[nbr]));
	return (ft_putnbr_base(nbr / base, simb, base)
		+ ft_putnbr_base(nbr % base, simb, base));
}
