/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:46:17 by gboudrie          #+#    #+#             */
/*   Updated: 2017/02/06 17:35:17 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
#include <stdio.h>

double	collide_sph(t_obj r, t_obj o)
{
	double		a;
	double		b;
	double		c;
	double		d;

	a = r.vect.x * r.vect.x + r.vect.y * r.vect.y + r.vect.z * r.vect.z;
	b = 2 * r.vect.x * (r.pos.x - o.pos.x) +
		2 * r.vect.y * (r.pos.y - o.pos.y) +
		2 * r.vect.z * (r.pos.z - o.pos.z);
	c = o.pos.x * o.pos.x + o.pos.y * o.pos.y + o.pos.z * o.pos.z +
		r.pos.x * r.pos.x + r.pos.y * r.pos.y + r.pos.z * r.pos.z -
		2 * (o.pos.x * r.pos.x + o.pos.y * r.pos.y + o.pos.z * r.pos.z ) -
		o.siz * o.siz;
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	c = (- b - sqrt(d)) / (2 * a);
	d = (- b + sqrt(d)) / (2 * a);
	return (c < d ? c : d);
}

double	collide_pln(t_obj r, t_obj o)
{
	double		t;
	t_dot_3d	u;

	if (dot_prod(o.vect, r.vect) == 0)
		return (-1);
	u.x = o.pos.x - r.pos.x;
	u.y = o.pos.y - r.pos.y;
	u.z = o.pos.z - r.pos.z;
	t = dot_prod(o.vect, u) / dot_prod(o.vect, r.vect);
	return (t);
}

double	collide_cyl(t_obj r, t_obj o, t_obj cam)
{
	double		a;
	double		b;
	double		c;
	double		d;
	t_dot_3d	z;

	z = set_vect(0.0, 0.0, 1.0);
	r.pos = vect_3d_sub(r.pos, o.pos);
	r.vect = rotate_vect_axis(cam.vect, r.vect, ang_vect(z, o.vect));
	a = r.vect.x * r.vect.x + r.vect.y * r.vect.y;
	b = 2 * r.vect.x * r.pos.x + 2 * r.vect.y * r.pos.y;
	c = r.pos.x * r.pos.x + r.pos.y * r.pos.y - o.siz * o.siz;
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	c = (- b - sqrt(d)) / (2 * a);
	d = (- b + sqrt(d)) / (2 * a);
	return (c < d ? c : d);
}

double	collide_con(t_obj r, t_obj o, t_obj cam)
{
	double		a;
	double		b;
	double		c;
	double		d;
	t_dot_3d	z;

	z = set_vect(0.0, 0.0, 1.0);
	r.pos = vect_3d_sub(r.pos, o.pos);
	r.vect = rotate_vect_axis(cam.vect, r.vect, ang_vect(z, o.vect));
	a = r.vect.x * r.vect.x + r.vect.y * r.vect.y - r.vect.z * r.vect.z;
	b = 2 * r.vect.x * r.pos.x + 2 * r.vect.y * r.pos.y -
		2 * r.vect.z * r.vect.z;
	c = r.pos.x * r.pos.x + r.pos.y * r.pos.y -
		r.pos.z * r.pos.z * o.siz * o.siz;
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	c = (- b - sqrt(d)) / (2 * a);
	d = (- b + sqrt(d)) / (2 * a);
	return (c < d ? c : d);
}
