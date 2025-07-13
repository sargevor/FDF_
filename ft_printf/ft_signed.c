/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:36:34 by sargevor          #+#    #+#             */
/*   Updated: 2025/02/16 14:37:00 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_signed(long long nbr)
{
	if (nbr < 0)
		return (ft_putchar('-') + ft_putnbr_base(-nbr, "0123456789", 10));
	return (ft_putnbr_base(nbr, "0123456789", 10));
}
