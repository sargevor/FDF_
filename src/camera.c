/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:00:00 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/12 17:13:23 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_camera	*init_camera(void)
{
	t_camera	*camera;

	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->zoom = 20;
	camera->angle_x = 0;
	camera->angle_y = 0;
	camera->angle_z = 0;
	camera->offset_x = WIN_WIDTH / 2;
	camera->offset_y = WIN_HEIGHT / 2;
	camera->z_scale = 1;
	camera->is_iso = 1;
	return (camera);
}

void	reset_camera(t_camera *camera)
{
	camera->zoom = 20;
	camera->angle_x = 0;
	camera->angle_y = 0;
	camera->angle_z = 0;
	camera->offset_x = WIN_WIDTH / 2;
	camera->offset_y = WIN_HEIGHT / 2;
	camera->z_scale = 1;
	camera->is_iso = 1;
}

void	zoom_camera(t_camera *camera, int zoom_in)
{
	if (zoom_in)
	{
		if (camera->zoom < 100)
			camera->zoom += 2;
	}
	else
	{
		if (camera->zoom > 2)
			camera->zoom -= 2;
	}
}

void	rotate_camera(t_camera *camera, double x_rot, double y_rot)
{
	camera->angle_x += x_rot;
	camera->angle_y += y_rot;
	if (camera->angle_x > 6.28)
		camera->angle_x -= 6.28;
	if (camera->angle_x < 0)
		camera->angle_x += 6.28;
	if (camera->angle_y > 6.28)
		camera->angle_y -= 6.28;
	if (camera->angle_y < 0)
		camera->angle_y += 6.28;
}

void	update_2d_points(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			t_32(&data->map->points[i][j],
				&data->map->points_2d[i][j], data->camera);
			j++;
		}
		i++;
	}
}
