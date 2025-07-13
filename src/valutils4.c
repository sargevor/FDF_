/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valutils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:53:54 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/12 15:42:15 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	validate_map_lines(int fd, int w, int h)
{
	char	*line;
	int		result;

	result = process_and_validate_lines(fd, w, h);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (result);
}

int	validate_map_content(char *filename, int width, int height)
{
	int	fd;
	int	result;

	if (!validate_map_dimensions(width, height))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	result = validate_map_lines(fd, width, height);
	close(fd);
	return (result);
}

char	**read_file_lines(char *filename, int height)
{
	int		fd;
	char	**lines;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = ft_calloc(height + 1, sizeof(char *));
	if (!lines)
	{
		close(fd);
		return (NULL);
	}
	i = 0;
	while (i < height)
	{
		lines[i] = get_next_line(fd);
		if (!lines[i])
			break ;
		i++;
	}
	close(fd);
	return (lines);
}

void	init_graphics(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error_exit("Failed to initialize MLX");
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	if (!data->win)
		error_exit("Failed to create window");
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img)
		error_exit("Failed to create image");
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}
