/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:34:36 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/29 03:08:54 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <float.h>
# include "mlx/mlx.h"
# define FOV_LIMIT 1e20
# define WIDTH 800
# define HEIGHT 600
# define MOUSE_UP 4
# define MOUSE_DW 5
# define ESC 65307
# define K_UP 65362
# define K_DW 65364
# define K_LF 65361
# define K_RG 65363
# define K_C 99

typedef struct s_frac
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*image_ptr;
	int		bpp;
	int		s_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	off_x;
	double	off_y;
	double	zoom;
	int		max_it;
	char	*fract;
	int		fract_len;
}			t_frac;

int		end_program(t_frac *data);
void	init_struct(t_frac *data);
int		init_struct_mlx(t_frac *data, int init_c);
int		check_c_val(t_frac *data, char **av, int ac);
void	make_fractal(t_frac *data);
int		key_reader(int k_code, t_frac *data);
int		mouse_reader(int m_code, int x, int y, t_frac *data);
size_t	ft_strlen(const char *s);
void	print_error(void);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		str_is_float(char *str);
double	ft_atof(const char *str);
void	put_pixel(t_frac *data, int color);
char	*trim(char *str);
int		change_color(void);
void	print_image(t_frac *data, void (*f)(t_frac *));

#endif