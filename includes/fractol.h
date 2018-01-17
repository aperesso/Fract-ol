/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 21:37:42 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/17 00:08:49 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1000
# define HEIGHT 750
# define MAX_ITE 30

# define ESC 65307

# include "../libft/libft.h"
# include "../math_toolbox/includes/toolbox.h"
# include <mlx.h>
# include <math.h>

typedef struct		s_img
{
	void			*ptr;
	int				*data;
	int				bpp;
	int				sl;
	int				endian;
}					t_img;
typedef struct		s_mlx
{
	void			*win;
	void			*ptr;
	struct s_img	*img;
}					t_mlx;
typedef struct		s_complex
{
	double			im;
	double			r;
}					t_complex;
typedef struct		s_env
{
	struct s_mlx	*mlx;
	int				mode;
	t_vec2			origine;
	double			zoom;
}					t_env;
t_env				*launch_program(int ac, char **av);
t_img				*init_img(t_mlx *mlx);
void				*error(char *error_message);
t_img				*fill_img_pixel(t_img *img, int color, int x, int y);
void				clear_color(t_img *img, int color);
int					make_color(int red, int green, int blue);
int					key_hook(int keycode, t_mlx *mlx);

t_env				*mandelbrot(t_env *e);


#endif