/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooksutil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:28:36 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/12 15:28:55 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->camera->angle_x -= 0.05;
	else if (keycode == KEY_S)
		data->camera->angle_x += 0.05;
	else if (keycode == KEY_A)
		data->camera->angle_y -= 0.05;
	else if (keycode == KEY_D)
		data->camera->angle_y += 0.05;
	else if (keycode == KEY_Q)
		data->camera->angle_z -= 0.05;
	else if (keycode == KEY_E)
		data->camera->angle_z += 0.05;
	render_map(data);
	return (0);
}

void	setup_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, handle_keypress, data);
	mlx_hook(data->win, 17, 1L << 17, handle_close, data);
	mlx_hook(data->win, 4, 1L << 2, handle_mouse_press, data);
	mlx_hook(data->win, 5, 1L << 3, handle_mouse_release, data);
	mlx_hook(data->win, 6, 1L << 6, handle_mouse_move, data);
}
