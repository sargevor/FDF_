/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:58:32 by sargevor          #+#    #+#             */
/*   Updated: 2025/02/16 14:37:08 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr(char *str)
{
    int count;
    
    if (!str)
        return (ft_putstr("(null)"));
    count = 0;
    while (*str)
    {
        count += ft_putchar(*(str++));
    }
    return (count);
}