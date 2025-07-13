/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:13:13 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/12 15:42:22 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		error_exit("Usage: ./fdf <filename.fdf>");
	data = init_data();
	if (!data)
		error_exit("Failed to initialize data");
	initialize(data, argv[1]);
	create_2d_points(data->map, data->camera);
	init_graphics(data);
	render_map(data);
	setup_hooks(data);
	mlx_loop(data->mlx);
	free_all(data);
	return (0);
}
