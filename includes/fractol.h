/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:32:19 by alexia            #+#    #+#             */
/*   Updated: 2018/01/23 17:48:25 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define NB_THREAD 16
# define WIDTH 1100
# define HEIGHT 800

# define ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define I 34
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define CLICK 1

// # define ESC 65307
// # define KEY_UP 65362
// # define KEY_DOWN 65364
// # define KEY_LEFT 65361
// # define KEY_RIGHT 65363
// # define I 105
// # define SCROLL_UP 5
// # define SCROLL_DOWN 4
// # define CLICK 1

# include "../libft/libft.h"
# include "../math_toolbox/includes/toolbox.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>

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
typedef struct		s_env
{
	struct s_mlx	*mlx;
	int				mode;
	t_vec2			origine;
	double			zoom;
	int				iteration;
	int				n_square;
}					t_env;
typedef struct		s_thread
{
	pthread_t		t;
	struct s_env	*env;
	int				id;
	t_vec2			tile[2];
}					t_thread;
typedef struct		s_complex
{
	double			r;
	double			im;
}					t_complex;
t_img				*init_img(t_mlx *mlx);
int					make_color(int red, int green, int blue);
void				clear_color(t_img *img, int color);
t_img				*fill_img_pixel(t_img *img, int color, int x, int y);
void				*error(char *error_message);
t_env				*launch_program(int ac, char **av);
int					thread_fractal(t_env *e);
void 				*mandelbrot(t_thread *t);
void				*julia(t_thread *t);
int					mouse_hook(int button, int x, int y, t_env *e);
int					mouse_move(int x, int y, t_env *e);

#endif
