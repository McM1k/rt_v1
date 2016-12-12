/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:56:13 by gboudrie          #+#    #+#             */
/*   Updated: 2016/12/12 16:48:12 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

void		img_addr(t_env env, int x, int y, int color)
{
	if (!(x > env.siz - 1 || x <= 0 || y <= 0 || x > SIZE_X || y > SIZE_Y))
		ft_memcpy(&env.img[(x - 1) * 4 + (y - 1) * env.siz], &color, 4);
}

int			check_objects(t_obj r, t_env env)
{
	t_list		*ptr;
	t_dot_3d	dot;
	int			col;

	ptr = env.list;
	col = 0;
	while (ptr)
	{
		if (ft_strcmp(((t_obj *)ptr->content)->name, "sph") == 0)
		{
			dot = collide_sph(r, *((t_obj *)ptr->content));
			if (dot.x != r.pos.x || dot.y != r.pos.y || dot.z != r.pos.z)
				col = ((t_obj *)ptr->content)->col;
// manque un test pour afficher la collision la plus proche et pas juste la derniere
		}
		ptr = ptr->next;
	}
	return (col);
}

int			rotate_ray(double x, double y, t_env env)
{
	t_obj	r;
	int		col;
	t_obj	cam;

	x *= (PI / 3) / SIZE_X;
	x -= (PI / 6);
	y *= (PI * (SIZE_X / SIZE_Y) / 3) / SIZE_Y;
	y -= (PI * (SIZE_X / SIZE_Y) / 6);
	cam = *((t_obj *)env.list->content);
	r.pos.x = cam.pos.x;
	r.pos.y = cam.pos.y;
	r.pos.z = cam.pos.z;
	r.vect = rotate_vect_y(cam.vect, x);
	r.vect = rotate_vect_z(r.vect, y);
	col = check_objects(r, env);
	return (col);
}

void		raycast(t_env env)
{
	double	x;
	double	y;

	x = 0;
	while (x++ < SIZE_X)
	{
		y = 0;
		while (y++ < SIZE_Y)
			img_addr(env, x, y, rotate_ray(x, y, env));
	}
}
