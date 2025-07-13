/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valutils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:56:07 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/12 15:05:12 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	validate_map_file(char *filename)
{
	if (!validate_file_extension(filename))
	{
		ft_printf("Error: Invalid file extension. Expected .fdf\n");
		return (0);
	}
	if (!validate_file_access(filename))
	{
		ft_printf("Error: Cannot open file %s\n", filename);
		return (0);
	}
	return (1);
}

int	validate_file_dimensions(int width, int height)
{
	if (width <= 0 || height <= 0)
	{
		ft_printf("Error: (width: %d, height: %d)\n", width, height);
		return (0);
	}
	if (width > 1000 || height > 1000)
	{
		ft_printf("Error: Map too large (max 1000x1000)\n");
		return (0);
	}
	return (1);
}

int	process_line(char *line, int width, int line_count, int is_last_line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
	{
		if (is_last_line)
		{
			ft_printf("Error: Last line should not end with newline\n");
			return (0);
		}
		line[len - 1] = '\0';
	}
	else if (!is_last_line)
	{
		ft_printf("Error: Non-last line must end with newline\n");
		return (0);
	}
	if (!validate_line_format(line, width))
	{
		ft_printf("Error: Invalid format in line %d\n", line_count);
		return (0);
	}
	return (1);
}

int	validate_map_dimensions(int width, int height)
{
	return (validate_file_dimensions(width, height));
}

int	is_empty_line(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
