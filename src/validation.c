/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 00:00:00 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/12 18:27:25 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	process_single_line(char *line, int width, int line_count, int is_last)
{
	if (is_empty_line(line))
	{
		ft_printf("Error: Empty line found at line %d\n", line_count);
		return (0);
	}
	if (!process_line(line, width, line_count, is_last))
		return (0);
	return (1);
}

int	process_and_validate_lines(int fd, int w, int h)
{
	char	*line;
	int		count;
	int		result;

	count = 0;
	result = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		if (!process_single_line(line, w, count, (count == h)))
			result = 0;
		free(line);
		line = get_next_line(fd);
	}
	if (result && count != h)
	{
		ft_printf("Error: Expected %d lines, found %d\n", h, count);
		result = 0;
	}
	return (result);
}

int	get_digit_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

int	check_overflow(long result, int digit, int base, int sign)
{
	if (result > (LONG_MAX - digit) / base)
	{
		if (sign == 1)
			return (1);
		else
			return (-1);
	}
	return (0);
}
