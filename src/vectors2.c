/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:14:22 by gboudrie          #+#    #+#             */
/*   Updated: 2017/02/04 12:44:15 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_dot_3d	vect_3d_uni(t_dot_3d u)
{
	return (vect_3d_div(u, sqrt(dot_prod(u, u))));
}

double		dot_prod(t_dot_3d u, t_dot_3d v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double		ang_vect(t_dot_3d u, t_dot_3d v)
{
	return (acos(dot_prod(u, v) / (sqrt(dot_prod(u, u))
								   * sqrt(dot_prod(v, v)))));
}

t_dot_3d	vect_3d_prod(t_dot_3d u, t_dot_3d v)
{
	t_dot_3d	w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
	return (w);
}
