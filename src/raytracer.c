/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:56:13 by gboudrie          #+#    #+#             */
/*   Updated: 2017/02/14 11:50:40 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
#include <stdio.h>

void		img_addr(t_env env, int x, int y, int color)
{
	if (!(x > env.siz - 1 || x <= 0 || y <= 0 || x > SIZE_X || y > SIZE_Y))
		ft_memcpy(&env.img[(x - 1) * 4 + (y - 1) * env.siz], &color, 4);
}

t_obj		*check_objects(t_obj r, t_env env, t_obj *cam, double param)
{
	t_list		*ptr;
	double		param_tmp;
	t_obj		*quad;
	t_func		func[4];

	quad = NULL;
	ptr = env.obj_lst;
	func[0] = collide_sph;
	func[1] = collide_pln;
	func[2] = collide_cyl;
	func[3] = collide_con;
	while (ptr)
	{
		param_tmp = func[((t_obj *)ptr->content)->
						 type](r,*((t_obj *)ptr->content), *cam);
		if (param_tmp > 0 && param_tmp < param && (param = param_tmp) > 0)
			quad = (t_obj *)(ptr->content);
		ptr = ptr->next;
	}
	cam->pos.x = r.pos.x + 0.0 + r.vect.x * param;
	cam->pos.y = r.pos.y + 0.0 + r.vect.y * param;
	cam->pos.z = r.pos.z + 0.0 + r.vect.z * param;
	return (quad);
}

int			rotate_ray(double x, double y, t_env env, t_dot_3d *tab)
{
	t_obj		r;
	int			col;
	t_obj		cam2;
	t_list		*ptr;
	t_obj		cam;

	cam2 = env.cam;
	cam = env.cam;
	r.pos = cam2.pos;
	r.vect = vect_3d_add(LFTUP, vect_3d_mul(RGHT, y * 0.5 / (double)SIZE_Y));
	r.vect = vect_3d_sub(r.vect, vect_3d_mul(UP, x * 0.5 / (double)SIZE_X));
	r.vect = vect_3d_uni(r.vect);
	col = check_objects(r, env, &cam2, 20000000);
	ptr = env.spot_lst;
	while (ptr)
	{
		cam2.vect.x = ((t_obj *)ptr->content)->pos.x - cam2.pos.x;
		cam2.vect.y = ((t_obj *)ptr->content)->pos.y - cam2.pos.y;
		cam2.vect.z = ((t_obj *)ptr->content)->pos.z - cam2.pos.z;
		cam2.pos.x = cam2.pos.x + cam2.vect.x * 0.01;
		cam2.pos.y = cam2.pos.y + cam2.vect.y * 0.01;
		cam2.pos.z = cam2.pos.z + cam2.vect.z * 0.01;
		if (check_objects(cam2, env, &cam, 1.0) != 0)
			col = shadow(col, 50);
		else
		{
			
			
		ptr = ptr->next;
	}
	return (col);
}

void		raycast(t_env env)
{
	double      x;
	double      y;
	t_dot_3d    tab[5];
	t_dot_3d    orth;
	double      an;

	CAMD = env.cam.vect;
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
	/**/	x = 0;
	while (x++ < SIZE_X)
	{
		y = 0;
		while (y++ < SIZE_Y)
			img_addr(env, x, y, rotate_ray(x, y, env, tab));
	}
	/**/
/*
	x = 250;
	y = 315;
	img_addr(env, x, y, rotate_ray(x, y, env, tab));
*/
}
