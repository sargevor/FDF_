/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:50:22 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/12 15:11:05 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	validate_hex_digits(char *str, int *i, int *has_digit)
{
	while (str[*i] && str[*i] != ',' && str[*i] != ' '
		&& str[*i] != '\t' && str[*i] != '\n')
	{
		if (!((str[*i] >= '0' && str[*i] <= '9')
				|| (str[*i] >= 'a' && str[*i] <= 'f')
				|| (str[*i] >= 'A' && str[*i] <= 'F')))
			return (0);
		*has_digit = 1;
		(*i)++;
	}
	return (1);
}

int	validate_octal_digits(char *str, int *i, int *has_digit)
{
	while (str[*i] && str[*i] != ',' && str[*i] != ' '
		&& str[*i] != '\t' && str[*i] != '\n')
	{
		if (!(str[*i] >= '0' && str[*i] <= '7'))
			return (0);
		*has_digit = 1;
		(*i)++;
	}
	return (1);
}

int	validate_decimal_digits(char *str, int *i, int *has_digit)
{
	while (str[*i] && str[*i] != ',' && str[*i] != ' '
		&& str[*i] != '\t' && str[*i] != '\n')
	{
		if (!(str[*i] >= '0' && str[*i] <= '9'))
			return (0);
		*has_digit = 1;
		(*i)++;
	}
	return (1);
}

int	is_valid_number_format(char *str)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
	{
		i += 2;
		return (validate_hex_digits(str, &i, &has_digit) && has_digit);
	}
	else if (str[i] == '0' && str[i + 1]
		&& str[i + 1] != ',' && str[i + 1] != ' ')
	{
		i++;
		return (validate_octal_digits(str, &i, &has_digit) && has_digit);
	}
	else
		return (validate_decimal_digits(str, &i, &has_digit) && has_digit);
}

int	is_valid_color_format(char *color_str)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	while (color_str[i] && (color_str[i] == ' ' || color_str[i] == '\t'))
		i++;
	if (!(color_str[i] == '0' && (color_str[i + 1] == 'x'
				|| color_str[i + 1] == 'X')))
		return (0);
	i += 2;
	while (color_str[i] && color_str[i] != ' ' && color_str[i] != '\t'
		&& color_str[i] != '\n')
	{
		if (!((color_str[i] >= '0' && color_str[i] <= '9')
				|| (color_str[i] >= 'a' && color_str[i] <= 'f')
				|| (color_str[i] >= 'A' && color_str[i] <= 'F')))
			return (0);
		has_digit = 1;
		i++;
	}
	return (has_digit);
}
