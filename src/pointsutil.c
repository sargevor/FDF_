/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointsutil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:10:43 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/13 11:55:32 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	apply_rotation_y(float *x, float *z, float angle_y)
{
	float	prev_x;

	prev_x = *x;
	*x = prev_x * cos(angle_y) + *z * sin(angle_y);
	*z = -prev_x * sin(angle_y) + *z * cos(angle_y);
}

void	apply_rotation_z(float *x, float *y, float angle_z)
{
	float	prev_x;
	float	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(angle_z) - prev_y * sin(angle_z);
	*y = prev_x * sin(angle_z) + prev_y * cos(angle_z);
}

void	apply_isometric(float *x, float *y, float z)
{
	float	iso_x;
	float	iso_y;

	iso_x = (*x - *y) * cos(0.523599);
	iso_y = (*x + *y) * sin(0.523599) - z;
	*x = iso_x;
	*y = iso_y;
}

t_2d_point	project(t_point p, t_camera *cam)
{
	t_2d_point	res;
	float		x;
	float		y;
	float		z;

	x = p.x * cam->zoom;
	y = p.y * cam->zoom;
	z = p.z * cam->zoom * cam->z_scale;
	apply_rotation_x(&y, &z, cam->angle_x);
	apply_rotation_y(&x, &z, cam->angle_y);
	apply_rotation_z(&x, &y, cam->angle_z);
	if (cam->is_iso)
		apply_isometric(&x, &y, z);
	res.x = (int)(x + cam->offset_x);
	res.y = (int)(y + cam->offset_y);
	res.color = p.color;
	return (res);
}
