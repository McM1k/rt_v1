/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:09:36 by gboudrie          #+#    #+#             */
/*   Updated: 2017/02/15 18:28:34 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_dot_3d	norm_sph(t_obj quad, t_dot_3d coll)
{
	t_dot_3d	norm;

	norm = vect_3d_sub(coll, quad.pos);
	return (norm);
}

t_dot_3d	norm_pln(t_obj quad, t_dot_3d coll)
{
	coll = quad.vect;
	return (coll);
}

t_dot_3d	norm_cyl(t_obj quad, t_dot_3d coll)
{
	t_dot_3d	norm;
	t_obj		tan;
	double		scal;
	t_dot_3d	v;

	tan.dir = quad.dir;
	tan.pos = coll;
	scal = dot_prod(quad.vect, tan.vect);
	if (scal)
		scal = dot_prod(vect_3d_sub(tan.pos, quad.pos), tan.vect) / scal;
	else
	{
		quad.vect = vect_3d_mul(quad.vect, -1);
		scal = dot_prod(quad.vect, tan.vect);
		scal = dot_prod(vect_3d_sub(tan.pos, quad.pos), tan.vect) / scal;
	}
	v = dot_prod(vect_3d_uni(cyl.dir), d);
	v = vect_3d_add(v, cyl.pos);
	norm = vect_3d_sub(coll, v);
	return (norm);
}

t_dot_3d	norm_con(t_obj quad, t_dot_3d coll)
{
	t_dot_3d	norm;
	t_obj		tan;
	double		scal;
	t_dot_3d	u;
	t_dot_3d	v;

	u = vect_3d_sub(coll, quad.pos);
	tan.dir = u;
	tan.pos = coll;
	scal = dot_prod(quad.vect, tan.vect);
	if (scal)
		scal = dot_prod(vect_3d_sub(tan.pos, quad.pos), tan.vect);
	else
	{
		quad.vect = vect_3d_mul(quad.vect, -1);
		scal = dot_prod(quad.vect, tan.vect);
		scal = dot_prod(vect_3d_sub(tan.pos, quad.pos), tan.vect);
	}
	v = vect_3d_mul(vect_3d_uni(quad.vect), scal);
	v = vect_3d_add(v, quad.pos);
	norm = vect_3d_sub(col, v);
	return (norm);
}
