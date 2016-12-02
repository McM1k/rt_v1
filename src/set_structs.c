/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_structs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:59:14 by gboudrie          #+#    #+#             */
/*   Updated: 2016/12/02 11:43:03 by gboudrie         ###   ########.fr       */
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
		sph.pos = coor_parse(&str, "-position[");
		sph.siz = value_parse(&str, "-size[");
		sph.col = color_parse(&str);
		ft_strdel(&str);
	}
	if (!(new = ft_lstnew((void *)(&sph), sizeof(t_obj))))
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
		cam.pos = coor_parse(&str, "-position[");
		cam.vect = coor_parse(&str, "-vector[");
		ft_strdel(&str);
	}
	if (!(new = ft_lstnew((void *)(&cam), sizeof(t_obj))))
		return (0);
	ft_lstadd(&(env->list), new);
	return (1);
}
