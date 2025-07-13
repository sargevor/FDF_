/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:00:00 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/12 17:13:23 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	return (data);
}

static int	count_words(char *line)
{
	int		count;
	int		i;
	int		in_word;

	count = 0;
	i = 0;
	in_word = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (count);
}

static int	get_map_dimensions(char *filename, int *width, int *height)
{
	int		fd;
	char	*line;
	int		first_line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	*height = 0;
	*width = 0;
	first_line = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (first_line)
		{
			*width = count_words(line);
			first_line = 0;
		}
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
	if (*width == 0 || *height == 0)
		return (close(fd), 0);
	return (close(fd), 1);
}

static t_map	*initialize_and_validate_map(char *filename)
{
	t_map	*map;

	if (!validate_map_file(filename))
	{
		ft_printf("Error: Map file validation failed\n");
		return (NULL);
	}
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	if (!get_map_dimensions(filename, &map->width, &map->height))
	{
		ft_printf("Error: Failed to get map dimensions\n");
		free(map);
		return (NULL);
	}
	if (!validate_map_content(filename, map->width, map->height))
	{
		ft_printf("Error: Map content validation failed\n");
		free(map);
		return (NULL);
	}
	return (map);
}

t_map	*read_map(char *filename)
{
	t_map	*map;
	char	**lines;
	int		i;

	map = initialize_and_validate_map(filename);
	if (!map)
		return (NULL);
	lines = read_file_lines(filename, map->height);
	if (!lines)
	{
		ft_printf("Error: Failed to read file lines\n");
		free(map);
		return (NULL);
	}
	get_next_line(-1);
	create_3d_points(map, lines);
	i = 0;
	while (i < map->height && lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	return (map);
}
