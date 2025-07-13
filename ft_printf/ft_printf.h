/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:03:38 by sargevor          #+#    #+#             */
/*   Updated: 2025/02/16 13:56:23 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_printf(const char *s, ...);
int	ft_choose(const char *s, va_list list);
int	ft_check(char c);
int	ft_putnbr_base(unsigned int nbr, char *simb, unsigned int base);
int	ft_signed(long long nbr);
int	ft_putptr(size_t nbr, char *simb, size_t base);

#endif
