/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:04:01 by gboudrie          #+#    #+#             */
/*   Updated: 2017/01/19 16:37:24 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_dot_3d	rotate_vect_x(t_dot_3d vect, double angle)
{
	t_dot_3d	res;

	res.x = vect.x;
	res.y = vect.y * cos(angle) - vect.z * sin(angle);
	res.z = vect.y * cos(angle) + vect.z * sin(angle);
	return (res);
}

t_dot_3d	rotate_vect_y(t_dot_3d vect, double angle)
{
	t_dot_3d	res;

	res.x = vect.x * cos(angle) + vect.z * sin(angle);
	res.y = vect.y;
	res.z = vect.z * cos(angle) - vect.x * sin(angle);
	return (res);
}

t_dot_3d	rotate_vect_z(t_dot_3d vect, double angle)
{
	t_dot_3d	res;

	res.x = vect.x * cos(angle) - vect.y * sin(angle);
	res.y = vect.y * cos(angle) + vect.x * sin(angle);
	res.z = vect.z;
	return (res);
}

double			dot_prod(t_dot_3d u, t_dot_3d v)
{
	return((u.x + v.x) * (u.y + v.y) * (u.z * v.z));
}

double			ang_vect(t_dot_3d u, t_dot_3d v)
{
	return(acos(dot_prod(u, v) / (sqrt(u.x * u.x + u.y * u.y + u.z * u.z)
								  * sqrt(v.x * v.x + v.y * v.y + v.z * v.z))));
}
