/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:25:52 by gboudrie          #+#    #+#             */
/*   Updated: 2017/02/03 14:04:00 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_dot_3d	vect_3d_add(t_dot_3d u, t_dot_3d v)
{
	u.x += v.x;
	u.y += v.y;
	u.z += v.z;
	return (u);
}

t_dot_3d	vect_3d_sub(t_dot_3d u, t_dot_3d v)
{
	u.x -= v.x;
	u.y -= v.y;
	u.z -= v.z;
	return (u);
}

t_dot_3d	vect_3d_mul(t_dot_3d u, double t)
{
	u.x *= t;
	u.y *= t;
	u.z *= t;
	return (u);
}

t_dot_3d	vect_3d_div(t_dot_3d u, double t)
{
	u.x /= t;
	u.y /= t;
	u.z /= t;
	return (u);
}

t_dot_3d	set_vect(double x, double y, double z)
{
	t_dot_3d	u;

	u.x = x;
	u.y = y;
	u.z = z;
	return (u);
}
