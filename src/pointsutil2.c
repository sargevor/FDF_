/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointsutil2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:11:32 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/13 11:55:51 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	t_32(t_point *point_3d, t_2d_point *point_2d, t_camera *camera)
{
	*point_2d = project(*point_3d, camera);
}

void	allocate_2d_row(t_map *map, int i)
{
	map->points_2d[i] = ft_calloc(map->width, sizeof(t_2d_point));
	if (!map->points_2d[i])
		error_exit("Failed to allocate memory for 2d point row");
}

void	process_2d_row(t_map *map, t_camera *camera, int i)
{
	int	j;

	j = 0;
	while (j < map->width)
	{
		t_32(&map->points[i][j], &map->points_2d[i][j], camera);
		j++;
	}
}

void	create_2d_points(t_map *map, t_camera *camera)
{
	int	i;

	map->points_2d = ft_calloc(map->height, sizeof(t_2d_point *));
	if (!map->points_2d)
		error_exit("Failed to allocate memory for 2d points");
	i = 0;
	while (i < map->height)
	{
		allocate_2d_row(map, i);
		process_2d_row(map, camera, i);
		i++;
	}
}
