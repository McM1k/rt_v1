/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:56:13 by gboudrie          #+#    #+#             */
/*   Updated: 2017/02/06 17:33:39 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

void		img_addr(t_env env, int x, int y, int color)
{
	if (!(x > env.siz - 1 || x <= 0 || y <= 0 || x > SIZE_X || y > SIZE_Y))
		ft_memcpy(&env.img[(x - 1) * 4 + (y - 1) * env.siz], &color, 4);
}

int			check_objects(t_obj r, t_env env, t_obj cam)
{
	t_list		*ptr;
	double		param_tmp;
	double		param;
	int			col;

	col = 0;
	ptr = env.list;
	param = 200000000;
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
			param_tmp = collide_cyl(r, *((t_obj *)ptr->content), cam);
			if (param_tmp > 0 && param_tmp < param && (param = param_tmp) > 0)
				col = ((t_obj *)ptr->content)->col;
		}
		else if (ft_strcmp(((t_obj *)ptr->content)->name, "con") == 0)
		{
			param_tmp = collide_con(r, *((t_obj *)ptr->content), cam);
			if (param_tmp > 0 && param_tmp < param && (param = param_tmp) > 0)
				col = ((t_obj *)ptr->content)->col;
		}
		ptr = ptr->next;
	}
	return (col);
}

int			rotate_ray(double x, double y, t_env env, t_dot_3d *tab)
{
	t_obj		r;
	int			col;
	t_obj		cam;

	cam = *((t_obj *)env.list->content);
	r.pos = cam.pos;
	r.vect = vect_3d_add(LFTUP, vect_3d_mul(RGHT, y * 0.5 / (double)SIZE_Y));
	r.vect = vect_3d_sub(r.vect, vect_3d_mul(UP, x * 0.5 / (double)SIZE_X));
/*	r.pos = cam.pos;
	r.vect.z = (SIZE_X + SIZE_Y) / 2;
	r.vect.y = -(SIZE_Y / 2) + x;
	r.vect.x = -(SIZE_X / 2) + y;
	rot = angs_vect(r.vect);
	r.vect = rotate_vect_x(cam.vect, rot.x);
	r.vect = rotate_vect_y(r.vect, rot.y);
	r.vect = rotate_vect_z(r.vect, rot.z);
*/
/*	x *= (PI / 3) / SIZE_X;
	x -= (PI / 6);
	y *= (PI / 3) / SIZE_Y;
	y -= (PI / 6);
	r.pos.x = cam.pos.x;
	r.pos.y = cam.pos.y;
	r.pos.z = cam.pos.z;
	r.vect = rotate_vect_y(cam.vect, y);
	r.vect = rotate_vect_z(r.vect, x);
*/
	col = check_objects(r, env, cam);
	return (col);
}

void		raycast(t_env env)
{
	double      x;
	double      y;
	t_dot_3d    tab[5];
	t_dot_3d    orth;
	double      an;

	CAMD = (*((t_obj *)env.list->content)).vect;
	RGHT = set_vect(1.0, 0.0, 0.0);
	UP = set_vect(0.0, 1.0, 0.0);
	FWD = set_vect(0.0, 0.0, 1.0);
	orth = vect_3d_uni(vect_3d_prod(FWD, CAMD));
	an = ang_vect(FWD, CAMD);
	if (an != 0.0)
	{
		RGHT = rotate_vect_axis(orth, RGHT, an);
		UP = rotate_vect_axis(orth, UP, an);
	}
	LFTUP = set_vect(0.0, 0.0, 0.0);
	LFTUP = vect_3d_add(LFTUP, vect_3d_mul(CAMD, 1.0));
	LFTUP = vect_3d_add(LFTUP, vect_3d_mul(UP, 0.25));
	LFTUP = vect_3d_sub(LFTUP, vect_3d_mul(RGHT, 0.25));
	x = 0;
	while (x++ < SIZE_X)
	{
		y = 0;
		while (y++ < SIZE_Y)
			img_addr(env, x, y, rotate_ray(x, y, env, tab));
	}
}
