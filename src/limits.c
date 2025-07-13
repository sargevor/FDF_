/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:00:00 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/12 17:13:23 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	should_connect(int x, int y, int width, int height)
{
	if (x < 0 || y < 0 || x >= width || y >= height)
		return (0);
	return (1);
}

void	connect_points(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			if (j + 1 < data->map->width)
			{
				draw_line(data, data->map->points_2d[i][j],
					data->map->points_2d[i][j + 1]);
			}
			if (i + 1 < data->map->height)
			{
				draw_line(data, data->map->points_2d[i][j],
					data->map->points_2d[i + 1][j]);
			}
			j++;
		}
		i++;
	}
}

void	redraw_map(t_data *data)
{
	update_2d_points(data);
	render_map(data);
}
