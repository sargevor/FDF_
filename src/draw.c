/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:00:00 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/13 11:54:11 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = data->addr
			+ (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static void	init_line(t_line *line, t_2d_point p1, t_2d_point p2)
{
	line->x0 = p1.x;
	line->y0 = p1.y;
	line->x1 = p2.x;
	line->y1 = p2.y;
	line->dx = abs(line->x1 - line->x0);
	line->dy = abs(line->y1 - line->y0);
	if (line->x0 < line->x1)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->y0 < line->y1)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx - line->dy;
}

void	draw_line(t_data *data, t_2d_point p1, t_2d_point p2)
{
	t_line	line;

	init_line(&line, p1, p2);
	while (1)
	{
		my_mlx_pixel_put(data, line.x0, line.y0, p1.color);
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		line.e2 = 2 * line.err;
		if (line.e2 > -line.dy)
		{
			line.err -= line.dy;
			line.x0 += line.sx;
		}
		if (line.e2 < line.dx)
		{
			line.err += line.dx;
			line.y0 += line.sy;
		}
	}
}

void	render_map(t_data *data)
{
	int	i;
	int	j;

	ft_memset(data->addr, 0, WIN_HEIGHT * data->line_length);
	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			data->map->points_2d[i][j]
				= project(data->map->points[i][j], data->camera);
			j++;
		}
		i++;
	}
	connect_points(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
