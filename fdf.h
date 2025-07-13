/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:00:00 by sargevor          #+#    #+#             */
/*   Updated: 2025/07/13 11:52:30 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "limits.h"

# define WIDTH 1920
# define HEIGHT 1080
# define ESC_KEY 65307
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_LEFT_BUTTON 1
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_R 114
# define KEY_T 116
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_Q 12
# define KEY_E 14

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_point;

typedef struct s_2d_point
{
	int		x;
	int		y;
	int		color;
}	t_2d_point;

typedef struct s_map
{
	int			width;
	int			height;
	t_point		**points;
	t_2d_point	**points_2d;
}	t_map;

typedef struct s_camera
{
	int		zoom;
	double	angle_x;
	double	angle_y;
	double	angle_z;
	int		offset_x;
	int		offset_y;
	int		z_scale;
	int		is_iso;
}	t_camera;

typedef struct s_mouse
{
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
	int		is_pressed;
}	t_mouse;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		*map;
	t_camera	*camera;
	t_mouse		*mouse;
}	t_data;

typedef struct s_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_line;

t_camera	*init_camera(void);
void		reset_camera(t_camera *camera);
void		zoom_camera(t_camera *camera, int zoom_in);
void		rotate_camera(t_camera *camera, double x_rot, double y_rot);
void		update_2d_points(t_data *data);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_line(t_data *data, t_2d_point p1, t_2d_point p2);
void		render_map(t_data *data);

void		initialize(t_data *data, char *file);
void		free_all(t_data *data);
void		free_map(t_map *map);
void		error_exit(char *msg);

int			handle_keypress(int keycode, t_data *data);
int			handle_close(t_data *data);
int			handle_mouse_press(int button, int x, int y, t_data *data);
int			handle_mouse_release(int button, int x, int y, t_data *data);
int			handle_mouse_move(int x, int y, t_data *data);

int			key_hook(int keycode, t_data *data);
void		setup_hooks(t_data *data);

int			should_connect(int x, int y, int width, int height);
void		connect_points(t_data *data);
void		redraw_map(t_data *data);

void		parse_color_value(char *value, t_point *point);
void		parse_line_values(char *line, t_point *points, int width);
void		allocate_point_row(t_map *map, int i);
void		create_3d_points(t_map *map, char **lines);
void		apply_rotation_x(float *y, float *z, float angle_x);
void		apply_rotation_y(float *x, float *z, float angle_y);
void		apply_rotation_z(float *x, float *y, float angle_z);
void		apply_isometric(float *x, float *y, float z);
t_2d_point	project(t_point p, t_camera *cam);

void		t_32(t_point *point_3d, t_2d_point *point_2d, t_camera *camera);
void		allocate_2d_row(t_map *map, int i);
void		process_2d_row(t_map *map, t_camera *camera, int i);
void		create_2d_points(t_map *map, t_camera *camera);

t_data		*init_data(void);
t_map		*read_map(char *filename);

int			process_single_line(char *line, int width,
				int line_count, int is_last);
int			process_and_validate_lines(int fd, int w, int h);
int			get_digit_value(char c);
int			check_overflow(long result, int digit, int base, int sign);
int			validate_hex_digits(char *str, int *i, int *has_digit);
int			validate_octal_digits(char *str, int *i, int *has_digit);
int			validate_decimal_digits(char *str, int *i, int *has_digit);
int			is_valid_number_format(char *str);
int			is_valid_color_format(char *color_str);

int			validate_map_file(char *filename);
int			validate_file_dimensions(int width, int height);
int			process_line(char *line, int width,
				int line_count, int is_last_line);
int			validate_map_dimensions(int width, int height);
int			is_empty_line(char *line);

int			validate_file_access(char *filename);
int			validate_file_extension(char *filename);
int			validate_line_format(char *line, int expected_width);
int			validate_values(char **values, int width);
int			free_and_return(char **values, int result);

unsigned	int	parse_validated_color(char *str);
int			determine_base(char *str);
long		safe_atoi_base(char *str, int base);
void		safe_atoi_base_util(char *str, int *i, int base, int *sign);

int			validate_map_lines(int fd, int w, int h);
int			validate_map_content(char *filename, int width, int height);
char		**read_file_lines(char *filename, int height);
void		init_graphics(t_data *data);

char		*get_next_line(int fd);
int			ft_printf(const char *format, ...);

#endif
