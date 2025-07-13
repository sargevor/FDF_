/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valutils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:57:40 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/12 15:27:03 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	free_and_return(char **values, int result)
{
	int	i;

	i = 0;
	while (values[i])
	{
		free(values[i]);
		i++;
	}
	free(values);
	return (result);
}

int	validate_values(char **values, int width)
{
	int		i;
	char	*comma_pos;

	i = 0;
	while (i < width && values[i])
	{
		if (!is_valid_number_format(values[i]))
			return (0);
		comma_pos = ft_strchr(values[i], ',');
		if (comma_pos)
		{
			comma_pos++;
			if (!is_valid_color_format(comma_pos))
				return (0);
		}
		i++;
	}
	return (1);
}

int	validate_line_format(char *line, int expected_width)
{
	char	**values;
	int		actual_width;

	if (!line || !*line)
		return (0);
	values = ft_split(line, ' ');
	if (!values)
		return (0);
	actual_width = 0;
	while (values[actual_width])
		actual_width++;
	if (actual_width != expected_width)
		return (free_and_return(values, 0));
	if (!validate_values(values, actual_width))
		return (free_and_return(values, 0));
	return (free_and_return(values, 1));
}

int	validate_file_extension(char *filename)
{
	char	*dot_pos;
	int		len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	dot_pos = ft_strrchr(filename, '.');
	if (!dot_pos)
		return (0);
	return (ft_strncmp(dot_pos, ".fdf", 4) == 0 && dot_pos[4] == '\0');
}

int	validate_file_access(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}
