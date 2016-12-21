/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:56:13 by gboudrie          #+#    #+#             */
/*   Updated: 2016/12/21 17:27:42 by gboudrie         ###   ########.fr       */
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
	double		param_tmp;
	double		param;
	int			col;

	col = 0;
	ptr = env.list;
	param = 2000000000;
	while (ptr)
	{
		if (ft_strcmp(((t_obj *)ptr->content)->name, "pln") == 0)
		{
			param_tmp = collide_pln(r, *((t_obj *)ptr->content));
			if (param_tmp > 0 && param_tmp < param && (param = param_tmp) > 0)
				col = ((t_obj *)ptr->content)->col;
		}
		else if (ft_strcmp(((t_obj *)ptr->content)->name, "sph") == 0)
		{
			param_tmp = collide_sph(r, *((t_obj *)ptr->content));
			if (param_tmp > 0 && param_tmp < param && (param = param_tmp) > 0)
				col = ((t_obj *)ptr->content)->col;
		}
		else if (ft_strcmp(((t_obj *)ptr->content)->name, "cyl") == 0)
		{
			param_tmp = collide_cyl(r, *((t_obj *)ptr->content));
			if (param_tmp > 0 && param_tmp < param && (param = param_tmp) > 0)
				col = ((t_obj *)ptr->content)->col;
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
	r.vect = rotate_vect_y(cam.vect, y);
	r.vect = rotate_vect_z(r.vect, x);
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
