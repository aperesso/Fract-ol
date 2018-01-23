/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 03:27:33 by alexia            #+#    #+#             */
/*   Updated: 2018/01/23 18:21:44 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//  void mainImage( out vec4 fragColor, in vec2 fragCoord ) 
//  { 
//      vec2 p = 1.05*(-iResolution.xy+2.0*fragCoord.xy)/iResolution.y; 
// 	 p.x -= 0.8;	
// 	 vec2 z = p;
// 	 vec2 dz = vec2(0.7, 0.4);
// 	 float t0 = 1e20;
// 	 float counter = 0.0;; 
//      for(int i=0;i<128;i++){ 
//          if(dot(z,z)>1024.0)break; 
//          dz=2.0*vec2(z.x*dz.x - z.y*dz.y, z.x*dz.y + z.y*dz.x);
//          z=vec2(z.x*z.x - z.y*z.y, 2.0*z.x*z.y) + p; 
//          t0=min(t0, dot(dz,dz));
//          counter++;
//      } 
//      float d=sqrt(dot(z,z)/dot(dz,dz))*log(dot(z,z)); 
// 	 z=vec2(z.x*z.x - z.y*z.y, 2.0*z.x*z.y) + p; counter++;
//      z=vec2(z.x*z.x - z.y*z.y, 2.0*z.x*z.y) + p; counter++;
// 	 float c = counter - log(log(length(z))) / log(2.0);
// 	 d = pow(d, 0.25);
// 	 t0 = pow(t0, 0.1);
// 	 vec3 col0 = 0.3 + 0.5 * sin(0.45 * c + .3) * vec3(1.0);
// 	 vec3 col1 = 0.3 + 0.7 * sin(2.4 * d) * vec3(1., 1.2, 0.8);
// 	 vec3 col = col0 * col1 * t0;
// 	 col=pow(col, vec3(0.55));
//      fragColor = vec4(col.x / 10.0, col.y / 30.0, col.z, 1.0); 
//  }



static float	smooth_mandelbrot(t_complex c, t_thread *t, t_vec2 p)
{
	float		i;
	double		tmp;
	t_complex	z;
	t_complex	dz;
	t_vec2		dot;
	float		t0;

	i = -1;
	z.r = 0;
	z.im = 0;
	dz.r = 0.7;
	dz.im = 0.4;
	t0 = 1e20;
	while (++i < t->env->iteration && (z.r * z.r + z.im * z.im) < 1024)
	{
		dz.r = 2.0 * (z.r * dz.r - z.im * dz.im);
		dz.im = 2.0 * (z.r * dz.r + z.im * dz.im);
		tmp = z.r;
		z.r = z.r * z.r - z.im * z.im + c.r;
		z.im = 2 * tmp * z.im + c.im;
		t0 = min(t0, dz.r * dz.r + dz.im * dz.im);

	}
	dot = set_vector_2d(z.r * z.r + z.im * z.im, dz.r * dz.r + dz.im * dz.im);

	float d;
	d = sqrt(dot.x / dot.y) * log(dot.x);
	z.r = z.r * z.r - z.im * z.im + c.r;
	z.im = 2 * tmp * z.im + c.im;
	i += 2;
	i =  i - log(log(sqrt(dot.x))) / log(2.0);
	d = pow(d, 0.25);
	t0 =  pow(t0, 0.1);

	t_vec3 col0;
	t_vec3 col1;
	t_vec3 col;

	float a;
	a = 0.3 + 0.5 * sin(0.45 * i + 0.3);
	col0 = set_vector_3d(a, a, a);
	a = 0.3 + 0.7 * sin(2.4 * d);
	col1 = set_vector_3d(a, a * 1.2, a * 0.8);
	col = set_vector_3d(col0.x * col1.x * t0, col0.y * col1.y * t0, col0.z * col1.z * t0);
	col = set_vector_3d(pow(col.x, 0.55) * 255 , pow(col.y, 0.55) * 255,  pow(col.z, 0.55) * 255);

	fill_img_pixel(t->env->mlx->img, make_color(col.x, col.y, col.z), p.x, p.y);
	return (i);
}

void 			*mandelbrot(t_thread *t)
{
	t_vec2		pos;
	t_complex	c;
	int			i;

	pos.y = t->tile[0].y - 1;
	while (++pos.y < t->tile[1].y)
	{
		pos.x = t->tile[0].x - 1;
		while (++pos.x < t->tile[1].x)
		{
			c.r = map(pos.x, set_vector_2d(0, WIDTH),
				set_vector_2d(t->env->origine.x - t->env->zoom,
					t->env->origine.x + t->env->zoom));
			c.im = map(pos.y, set_vector_2d(0, HEIGHT),
				set_vector_2d(t->env->origine.y - t->env->zoom,
					t->env->origine.y + t->env->zoom));
			i = smooth_mandelbrot(c, t, pos);
		}
	}
	return (t);
}
