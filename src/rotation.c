/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:04:01 by gboudrie          #+#    #+#             */
/*   Updated: 2017/02/03 14:34:56 by gboudrie         ###   ########.fr       */
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

t_dot_3d	rotate_vect_axis(t_dot_3d ax, t_dot_3d u, double an)
{
	t_dot_3d	tmp;

	tmp = ax;
	ax.x = u.x * (cos(an) + (tmp.x * tmp.x) * (1 - cos(an))) +
		u.y * (tmp.x * tmp.y * (1 - cos(an)) - tmp.z * sin(an)) +
		u.z * (tmp.x * tmp.z * (1 - cos(an)) + tmp.y * sin(an));
	ax.y = u.x * (tmp.y * tmp.x * (1 - cos(an)) + tmp.z * sin(an)) +
		u.y * (cos(an) + (tmp.y * tmp.y) * (1 - cos(an))) +
		u.z * (tmp.y * tmp.z * (1 - cos(an)) - tmp.x * sin(an));
	ax.z = u.x * (tmp.z * tmp.x * (1 - cos(an)) - tmp.y * sin(an)) +
		u.y * (tmp.z * tmp.y * (1 - cos(an)) + tmp.x * sin(an)) +
		u.z * (cos(an) + (tmp.z * tmp.z) * (1 - cos(an)));
	return (ax);
}
