/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:46:17 by gboudrie          #+#    #+#             */
/*   Updated: 2017/01/19 17:40:08 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

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

	if (!(o.vect.x * r.vect.x + o.vect.y * r.vect.y + o.vect.z * r.vect.z))
		return (-1);
	t = o.vect.x * (o.pos.x - r.pos.x)
		+ o.vect.y * (o.pos.y - r.pos.y)
		+ o.vect.z * (o.pos.z - r.pos.z)
		/ (o.vect.x * r.vect.x + o.vect.y * r.vect.y + o.vect.z * r.vect.z);
	return (t);
}

double	collide_cyl(t_obj r, t_obj o)
{
	double	a;
	double	b;
	double	c;
	double	d;

	r.pos.x -= o.pos.x;
	r.pos.y -= o.pos.y;
	r.pos.z -= o.pos.z;
	r.vect.x -= o.vect.x;
	r.vect.y -= o.vect.y;
	r.vect.z -= o.vect.z;
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

double	collide_con(t_obj r, t_obj o)
{
	double	a;
	double	b;
	double	c;
	double	d;

	r.pos.x -= o.pos.x;
	r.pos.y -= o.pos.y;
	r.pos.z -= o.pos.z;
	r.vect.x -= o.vect.x;
	r.vect.y -= o.vect.y;
	r.vect.z -= o.vect.z;
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
