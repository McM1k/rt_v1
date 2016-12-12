/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:04:01 by gboudrie          #+#    #+#             */
/*   Updated: 2016/12/12 16:21:14 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_dot_3d	rotate_vect_x(t_dot_3d vect, double angle)
{
	vect.y = vect.y + (cos(angle) - sin(angle));
	vect.z = vect.z + (cos(angle) + sin(angle));
	return (vect);
}

t_dot_3d	rotate_vect_y(t_dot_3d vect, double angle)
{
	vect.x = vect.x + (cos(angle) + sin(angle));
	vect.z = vect.z + (cos(angle) - sin(angle));
	return (vect);
}

t_dot_3d	rotate_vect_z(t_dot_3d vect, double angle)
{
	vect.x = vect.x + (cos(angle) - sin(angle));
	vect.y = vect.y + (cos(angle) + sin(angle));
	return (vect);
}
