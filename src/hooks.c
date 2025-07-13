/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:00:00 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/12 17:13:23 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		free_all(data);
		exit(0);
	}
	else if (keycode == KEY_PLUS)
		zoom_camera(data->camera, 1);
	else if (keycode == KEY_MINUS)
		zoom_camera(data->camera, 0);
	else if (keycode == KEY_LEFT)
		data->camera->offset_x -= 10;
	else if (keycode == KEY_RIGHT)
		data->camera->offset_x += 10;
	else if (keycode == KEY_UP)
		data->camera->offset_y -= 10;
	else if (keycode == KEY_DOWN)
		data->camera->offset_y += 10;
	else if (keycode == KEY_R)
		reset_camera(data->camera);
	else if (keycode == KEY_T)
		data->camera->is_iso = !data->camera->is_iso;
	redraw_map(data);
	return (0);
}

int	handle_close(t_data *data)
{
	free_all(data);
	exit(0);
	return (0);
}

int	handle_mouse_press(int button, int x, int y, t_data *data)
{
	if (button == MOUSE_WHEEL_UP)
		zoom_camera(data->camera, 1);
	else if (button == MOUSE_WHEEL_DOWN)
		zoom_camera(data->camera, 0);
	else if (button == MOUSE_LEFT_BUTTON)
	{
		data->mouse->is_pressed = 1;
		data->mouse->prev_x = x;
		data->mouse->prev_y = y;
	}
	redraw_map(data);
	return (0);
}

int	handle_mouse_release(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == MOUSE_LEFT_BUTTON)
		data->mouse->is_pressed = 0;
	return (0);
}

int	handle_mouse_move(int x, int y, t_data *data)
{
	if (data->mouse->is_pressed)
	{
		rotate_camera(data->camera,
			(y - data->mouse->prev_y) * 0.01,
			(x - data->mouse->prev_x) * 0.01);
		data->mouse->prev_x = x;
		data->mouse->prev_y = y;
		redraw_map(data);
	}
	return (0);
}
