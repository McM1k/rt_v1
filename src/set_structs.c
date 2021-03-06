/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_structs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:59:14 by gboudrie          #+#    #+#             */
/*   Updated: 2017/01/09 13:18:04 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			set_sph(int *fd, t_env *env)
{
	t_list		*new;
	t_obj		sph;
	char		*str;

	sph.name[0] = 's';
	sph.name[1] = 'p';
	sph.name[2] = 'h';
	sph.name[3] = '\0';
	while ((get_next_line(*fd, &str)) > 0 && *str != '}')
	{
		if ((ft_strnequ("-position[", str, 10)))
			sph.pos = coor_parse(&str, "-position[");
		else if ((ft_strnequ("-size[", str, 6)))
			sph.siz = value_parse(&str, "-size[");
		else if ((ft_strnequ("-colour[", str, 8)))
			sph.col = color_parse(&str);
		ft_strdel(&str);
	}
	if (!(new = ft_lstnew((void *)(&sph), sizeof(t_obj))))
		return (0);
	ft_lstaddq(&(env->list), new);
	return (1);
}

int			set_pln(int *fd, t_env *env)
{
	t_list		*new;
	t_obj		pln;
	char		*str;

	pln.name[0] = 'p';
	pln.name[1] = 'l';
	pln.name[2] = 'n';
	pln.name[3] = '\0';
	while ((get_next_line(*fd, &str)) > 0 && *str != '}')
	{
		if ((ft_strnequ("-position[", str, 10)))
			pln.pos = coor_parse(&str, "-position[");
		else if ((ft_strnequ("-vector[", str, 8)))
			pln.vect = coor_parse(&str, "-vector[");
		else if ((ft_strnequ("-colour[", str, 8)))
			pln.col = color_parse(&str);
		ft_strdel(&str);
	}
	if (!(new = ft_lstnew((void *)(&pln), sizeof(t_obj))))
		return (0);
	ft_lstaddq(&(env->list), new);
	return (1);
}

int			set_cyl(int *fd, t_env *env)
{
	t_list		*new;
	t_obj		cyl;
	char		*str;

	cyl.name[0] = 'c';
	cyl.name[1] = 'y';
	cyl.name[2] = 'l';
	cyl.name[3] = '\0';
	while ((get_next_line(*fd, &str)) > 0 && *str != '}')
	{
		if ((ft_strnequ("-position[", str, 10)))
			cyl.pos = coor_parse(&str, "-position[");
		else if ((ft_strnequ("-vector[", str, 8)))
			cyl.vect = coor_parse(&str, "-vector[");
		else if ((ft_strnequ("-size[", str, 6)))
			cyl.siz = value_parse(&str, "-size[");
		else if ((ft_strnequ("-colour[", str, 8)))
			cyl.col = color_parse(&str);
		ft_strdel(&str);
	}
	if (!(new = ft_lstnew((void *)(&cyl), sizeof(t_obj))))
		return (0);
	ft_lstaddq(&(env->list), new);
	return (1);
}

int			set_con(int *fd, t_env *env)
{
	t_list		*new;
	t_obj		con;
	char		*str;

	con.name[0] = 'c';
	con.name[1] = 'o';
	con.name[2] = 'n';
	con.name[3] = '\0';
	while ((get_next_line(*fd, &str)) > 0 && *str != '}')
	{
		if ((ft_strnequ("-position[", str, 10)))
			con.pos = coor_parse(&str, "-position[");
		else if ((ft_strnequ("-vector[", str, 8)))
			con.vect = coor_parse(&str, "-vector[");
		else if ((ft_strnequ("-size[", str, 6)))
			con.siz = value_parse(&str, "-size[");
		else if ((ft_strnequ("-colour[", str, 8)))
			con.col = color_parse(&str);
		ft_strdel(&str);
	}
	if (!(new = ft_lstnew((void *)(&con), sizeof(t_obj))))
		return (0);
	ft_lstaddq(&(env->list), new);
	return (1);
}

int			set_cam(int *fd, t_env *env)
{
	t_list		*new;
	t_obj		cam;
	char		*str;

	cam.name[0] = 'c';
	cam.name[1] = 'a';
	cam.name[2] = 'm';
	cam.name[3] = '\0';
	while ((get_next_line(*fd, &str)) > 0 && *str != '}')
	{
		if ((ft_strnequ("-position[", str, 10)))
			cam.pos = coor_parse(&str, "-position[");
		else if ((ft_strnequ("-vector[", str, 8)))
			cam.vect = coor_parse(&str, "-vector[");
		ft_strdel(&str);
	}
	if (!(new = ft_lstnew((void *)(&cam), sizeof(t_obj))))
		return (0);
	ft_lstadd(&(env->list), new);
	return (1);
}
