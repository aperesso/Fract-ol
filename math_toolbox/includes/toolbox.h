/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:54:00 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/27 03:26:35 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLBOX_H
# define TOOLBOX_H
# define DEGREESTORADIANS(angleDegrees) (angleDegrees * M_PI / 180.0)
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_matrix_3
{
	float			data[3][3];
}					t_matrix_3;
typedef struct		s_matrix
{
	float			data[4][4];
}					t_matrix;
typedef struct		s_vec2
{
	float			x;
	float			y;
}					t_vec2;
typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;
typedef struct		s_vec4
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vec4;
typedef struct		s_mesh
{
	t_vec3			position;
	t_vec3			scale;
	t_vec3			r;
	int				vertex_count;
	struct s_vec4	*vertices;
	struct s_vec4	*transformed_vertices;
	int				*color;
	int				*is_visible;
}					t_mesh;
t_matrix_3			create_matrix_3d(void);
t_matrix			create_matrix(void);
t_matrix			set_identity(void);
t_matrix_3			set_identity_3(void);
t_matrix			mult_matrix(t_matrix a, t_matrix b);
t_matrix_3			mult_matrix_3(t_matrix_3 a, t_matrix_3 b);
t_matrix			translate(float x, float y, float z);
t_matrix			rotatex(float t);
t_matrix			rotatey(float t);
t_matrix			rotatez(float t);
t_matrix_3			rotatex_3(float t);
t_matrix_3			rotatey_3(float t);
t_matrix_3			rotatez_3(float t);
t_matrix			scale(float sx, float sy, float sz);
t_vec4				mult_matrix_vector(t_matrix a, t_vec4	v);
t_vec3				mult_matrix_vector_3(t_matrix_3 a, t_vec3 v);
t_matrix			create_transformation_matrix(t_vec3 translation,
						t_vec3 rotate, t_vec3 scale);
t_matrix			create_view_matrix(t_vec3 position, float rx, float ry,
						float rz);
t_matrix			create_projection_matrix(float aspect, float fov,
						float far, float near);
t_mesh				new_mesh(int vertexcount, t_vec4 *vertices);
t_matrix			viewport_matrix(float x, float y, float width,
						float height);
t_vec4				set_vector_4d(float x, float y, float z, float w);
t_vec3				set_vector_3d(float x, float y, float z);
t_vec2				set_vector_2d(float x, float y);
float				map(float x, t_vec2 from, t_vec2 to);
float				mix(float v1, float v2, float a);
float 				clamp(float x, float lowerlimit, float upperlimit);
float				smoothstep(float edge0, float edge1, float x);
t_vec3				mix_vec3(t_vec3 v1, t_vec3 v2, t_vec3 v3);
float   			min(float a, float b);
float   			max(float a, float b);
t_vec3				cross_product(t_vec3 a, t_vec3 b);
float				dot_product(t_vec3 a, t_vec3 b);
t_vec2				normalize_2d(t_vec2 a);
t_vec3				normalize_3d(t_vec3 a);
t_vec4				normalize_4d(t_vec4 a);
t_vec2				sub_vec2(t_vec2 a, t_vec2 b);
t_vec3				sub_vec3(t_vec3 a, t_vec3 b);
t_vec4				sub_vec4(t_vec4 a, t_vec4 b);
t_vec2				add_vec2(t_vec2 a, t_vec2 b);
t_vec3				add_vec3(t_vec3 a, t_vec3 b);
t_vec4				add_vec4(t_vec4 a, t_vec4 b);
t_vec2				mul_vec2(t_vec2 a, float m);
t_vec3				mul_vec3(t_vec3 a, float m);
t_vec4				mul_vec4(t_vec4 a, float m);

#endif
