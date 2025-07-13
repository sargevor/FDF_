/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valutils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:59:25 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/12 18:22:13 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	safe_atoi_base_util(char *str, int *i, int base, int *sign)
{
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
	{
		(*i)++;
	}
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	if (base == 16 && str[*i] == '0' && (str[(*i) + 1] == 'x'
			|| str[(*i) + 1] == 'X'))
		(*i) += 2;
	else if (base == 8 && str[*i] == '0')
		(*i)++;
}

long	safe_atoi_base(char *str, int base)
{
	long	result;
	int		sign;
	int		i;
	int		digit;
	int		overflow;

	result = 0;
	sign = 1;
	i = 0;
	safe_atoi_base_util(str, &i, base, &sign);
	while (str[i] && str[i] != ',' && str[i] != ' '
		&& str[i] != '\t' && str[i] != '\n')
	{
		digit = get_digit_value(str[i]);
		if (digit < 0 || digit >= base)
			break ;
		overflow = check_overflow(result, digit, base, sign);
		if (overflow == 1)
			return (LONG_MAX);
		if (overflow == -1)
			return (LONG_MIN);
		result = result * base + digit;
		i++;
	}
	return (result * sign);
}

int	determine_base(char *str)
{
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		return (16);
	if (str[0] == '0' && str[1] && str[1] != ',' && str[1] != ' ')
		return (8);
	return (10);
}

unsigned int	parse_validated_color(char *str)
{
	long	result;

	if (!str || !is_valid_color_format(str))
		return (0xFFFFFF);
	result = safe_atoi_base(str, 16);
	if (result < 0 || result > 0xFFFFFF)
		return (0xFFFFFF);
	return ((unsigned int)result);
}
