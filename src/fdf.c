/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:00:00 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/12 17:13:23 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	error_exit(char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit(1);
}

static void	free_point_array(void **array, int height)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < height)
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	free_point_array((void **)map->points, map->height);
	free_point_array((void **)map->points_2d, map->height);
	free(map);
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
		free_map(data->map);
	if (data->camera)
		free(data->camera);
	if (data->mouse)
		free(data->mouse);
	free(data);
}

void	initialize(t_data *data, char *file)
{
	data->map = read_map(file);
	if (!data->map)
	{
		free_all(data);
		error_exit("Failed to read map");
	}
	data->camera = init_camera();
	if (!data->camera)
	{
		free_all(data);
		error_exit("Failed to initialize camera");
	}
	data->mouse = ft_calloc(1, sizeof(t_mouse));
	if (!data->mouse)
	{
		free_all(data);
		error_exit("Failed to initialize mouse");
	}
}
