/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:46:17 by gboudrie          #+#    #+#             */
/*   Updated: 2016/12/20 18:00:55 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

double	collide_sph(t_obj r, t_obj s)
{
	double		a;
	double		b;
	double		c;
	double		d;

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
		return (-1);
	c = (- b - sqrt(d)) / (2 * a);
	d = (- b + sqrt(d)) / (2 * a);
	return (c < d ? c : d);
}

double	collide_pln(t_obj r, t_obj p)
{
	double		t;

	if (!(p.vect.x * r.vect.x + p.vect.y * r.vect.y + p.vect.z * r.vect.z))
		return (-1);
	t = p.vect.x * (p.pos.x - r.pos.x)
		+ p.vect.y * (p.pos.y - r.pos.y)
		+ p.vect.z * (p.pos.z - r.pos.z)
		/ (p.vect.x * r.vect.x + p.vect.y * r.vect.y + p.vect.z * r.vect.z);
	return (t);
}
