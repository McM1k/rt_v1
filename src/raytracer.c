/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:56:13 by gboudrie          #+#    #+#             */
/*   Updated: 2016/11/17 17:21:58 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
/*
** Sphere = (x-a)2 + (y-b)2 + (z-c)2 - r2
** note a mwa meme : en fait y'a pas vraiment d'equation cartesienne de droite en 3d, limite y'a le systeme des equations de deux plans non paralleles qui peuvent definir une droite en leur intersection mais voila... bon courage.
*/

t_dot_3d	collide_sph(t_ray r, t_sphere s)
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
		s.size * s.size;
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
