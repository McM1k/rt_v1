/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:46:17 by gboudrie          #+#    #+#             */
/*   Updated: 2016/12/12 16:21:27 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
#include <stdio.h>
t_dot_3d	collide_sph(t_obj r, t_obj s)
{
	double		a;
	double		b;
	double		c;
	double		d;
	t_dot_3d	res;

//	printf("x = %lf, y = %lf, z = %lf\n",  r.vect.x, r.vect.y, r.vect.z);
/*	ft_putstr("x = ");
	ft_putnbr(r.vect.x);
	ft_putstr(", y = ");
	ft_putnbr(r.vect.y);
	ft_putstr(", z = ");
	ft_putnbr(r.vect.z);
	ft_putendl("");
*/	a = r.vect.x * r.vect.x + r.vect.y * r.vect.y + r.vect.z * r.vect.z;
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

t_dot_3d	collide_pln(t_obj r, t_obj p)
{
	double		t;
	t_dot_3d	res;

	if (!(p.vect.x * r.vect.x + p.vect.y * r.vect.y + p.vect.z * r.vect.z))
		return (r.pos);
	t = p.vect.x * (p.pos.x - r.pos.x)
		+ p.vect.y * (p.pos.y - r.pos.y)
		+ p.vect.z * (p.pos.z - r.pos.z)
		/ (p.vect.x * r.vect.x + p.vect.y * r.vect.y + p.vect.z * r.vect.z);
	res.x = r.pos.x + r.vect.x * t;
	res.y = r.pos.y + r.vect.y * t;
	res.z = r.pos.z + r.vect.z * t;
	return (res);
}
