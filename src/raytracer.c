/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:56:13 by gboudrie          #+#    #+#             */
/*   Updated: 2016/11/21 17:43:51 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_dot_3d	collide_sph(t_camera r, t_sphere s)
{
	double		a;
	double		b;
	double		c;
	double		d;
	t_dot_3d	res;

	a = r.vect.x * r.vect.x + r.vect.y * r.vect.y + r.vect.z * r.vect.z;
	b = 2 * r.vect.x * (r.pos.x - s.pos.x) +
		2 * r.vect.y * (r.pos.y - s.pos.y) +
		2 * r.vect.z * (r.pos.z - s.pos.z);
	c = s.pos.x * s.pos.x + s.pos.y * s.pos.y + s.pos.z * s.pos.z +
		r.pos.x * r.pos.x + r.pos.y * r.pos.y + r.pos.z * r.pos.z -
		2 * (s.pos.x * r.pos.x + s.pos.y * r.pos.y + s.pos.z * r.pos.z ) -
		s.siz * s.siz;
	d = b * b - 4 * a * c;
	if (d < 0)
		return (r.pos);
	c = (- b - sqrt(d)) / (2 * a);
	d = (- b + sqrt(d)) / (2 * a);
	res.x = (c < d ? r.pos.x + c * r.vect.x : r.pos.x + d * r.vect.x);
	res.y = (c < d ? r.pos.y + c * r.vect.y : r.pos.y + d * r.vect.y);
	res.z = (c < d ? r.pos.z + c * r.vect.z : r.pos.z + d * r.vect.z);
	return (res);
}

void		img_addr(t_env env, int x, int y, int color)
{
	if (!(x > env.siz - 1 || x <= 0 || y <= 0
		  || x > SIZE_X - 1 || y > SIZE_Y - 1))
		ft_memcpy(&env.img[(x - 1) * 4 + (y - 1) * env.siz], &color, 4);
}



int			check_objects(t_camera r, t_env env)
{
	t_list		*ptr;
	t_dot_3d	dot;
	int			col;

	ptr = env.list;
	while (ptr)
	{
		if (ft_strcmp((t_sphere)(ptr->name), "sph") == 0)
		{
			dot = collide_sph(r, (t_sphere)(*ptr));
			if (dot.x != r.pos.x || dot.y != r.pos.y || dot.z != r.pos.z)
				col = ptr->color;
// manque un test pour afficher la collision la plus proche et pas juste la derniere
		}
		ptr = ptr->next;
	}
	return (col);
}

int			rotate_ray(t_camera r, double x, double y, t_env env)
{
	int		col;

	r.vect.x = r.vect.x * (cos(y) + sin(y));
	r.vect.y = r.vect.y * (cos(x) - sin(x));
	r.vect.z = r.vect.z * (sin(x) + cos(x));
	r.vect.z = r.vect.z * (cos(y) - sin(y));
	col = check_objects(r, env);
	return (col);
}

void		raycast(t_env env)
{
	double	add_y;
	double	add_x;
	double	x;
	double	y;

	add_x = (PI / 3) / SIZE_X;
	add_y = (PI * (SIZE_X / SIZE_Y) / 3) / SIZE_Y;
	x = - (PI / 6);
	while (x < PI / 6)
	{
		y = - (PI * (SIZE_X / SIZE_Y) / 6);
		while (y < (PI * (SIZE_X / SIZE_Y) / 6))
		{
			img_addr(env, -*rotate_ray((t_camera)*(env.list), x, y, env))
			y += add_y;
		}
		x += add_x;
	}
}
