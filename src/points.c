/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:00:00 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/12 17:13:23 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	parse_color_value(char *value, t_point *point)
{
	char	*cp;

	cp = ft_strchr(value, ',');
	if (cp)
	{
		cp++;
		if (*cp == '0' && (*(cp + 1) == 'x' || *(cp + 1) == 'X'))
			point->color = ft_atoi(cp + 2);
		else
			point->color = 0xFFFFFF;
	}
	else
	{
		if (point->z > 0)
			point->color = 0xFF0000;
		else if (point->z < 0)
			point->color = 0x0000FF;
		else
			point->color = 0xFFFFFF;
	}
}

void	parse_line_values(char *line, t_point *points, int width)
{
	char	**values;
	int		i;

	values = ft_split(line, ' ');
	if (!values)
		return ;
	i = 0;
	while (i < width && values[i])
	{
		points[i].z = ft_atoi(values[i]);
		parse_color_value(values[i], &points[i]);
		free(values[i]);
		i++;
	}
	free(values);
}

void	allocate_point_row(t_map *map, int i)
{
	int	j;

	map->points[i] = ft_calloc(map->width, sizeof(t_point));
	if (!map->points[i])
		error_exit("Failed to allocate memory for point row");
	j = 0;
	while (j < map->width)
	{
		map->points[i][j].x = j;
		map->points[i][j].y = i;
		j++;
	}
}

void	create_3d_points(t_map *map, char **lines)
{
	int	i;

	map->points = ft_calloc(map->height, sizeof(t_point *));
	if (!map->points)
		error_exit("Failed to allocate memory for points");
	i = 0;
	while (i < map->height)
	{
		allocate_point_row(map, i);
		parse_line_values(lines[i], map->points[i], map->width);
		i++;
	}
}

void	apply_rotation_x(float *y, float *z, float angle_x)
{
	float	prev_y;

	prev_y = *y;
	*y = prev_y * cos(angle_x) - *z * sin(angle_x);
	*z = prev_y * sin(angle_x) + *z * cos(angle_x);
}
