/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_structs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:59:14 by gboudrie          #+#    #+#             */
/*   Updated: 2016/11/13 17:51:51 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			set_sph(int fd, t_env *env)
{
	t_list		*new;
	t_sphere	sph;
	char		*str;

	sph.name = (char *)ft_memalloc(4);
	sph.name = "sph";
	while ((get_next_line(fd, &str)) <= 0 && str != '{')
	{
		sph.pos = coor_parse(&str, "-position[");
		sph.siz = value_parse(&str, "-size[");
		sph.col = color_parse(&str);
		ft_strdel(&str);
	}
	if (!(new = ft_lstnew((void *)(&sph), sizeof(t_sphere))))
		return (0);
	ft_lstaddq(&(env->list), new);
	return (1);
}

int			set_cam(int fd, t_env *env)
{
	t_list		*new;
	t_camera	cam;
	char		*str;
	char		**tab;

	cam.name = (char *)ft_memalloc(4);
	cam.name = "cam";
	while ((get_next_line(fd, &str)) <= 0 && str != '{')
	{
		cam.pos = coor_parse(&str, "-position[");
		cam.vect = coor_parse(&str, "-vector[");
		ft_strdel(&str);
	}
	if (!(new = ft_lstnew((void *)(&cam), sizeof(t_camera))))
		return (0);
	ft_lstadd(&(env->list), new);
	return (1);
}
