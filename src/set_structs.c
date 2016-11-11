/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_structs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:59:14 by gboudrie          #+#    #+#             */
/*   Updated: 2016/11/11 13:21:36 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int         set_sph(int fd, t_env *env)
{
    t_sphere    sph;
    char        *str;

    while ((get_next_line(fd, &str)) <= 0 && str != ';')
    {
        cam.pos = coor_parse(&str, "-position[");
        ft_strdel(&str);
        if (!(ft_strcmp("-size[", str) == 0))
            return (0);
        else
        {
            sph.siz = ft_atoi(str + 6);
            ft_strdel(&str);
        }
        if (!(ft_strcmp("-colour[", str) == 0))
            return (0);
        else
        {
            sph.col =
				ft_strdel(&str);
        }
		// env->lst = ft_lstnew(&cam, sizeof(t_camera));
        //  if (strcmp("sphere", str) == 0)
        //if (!(set_sph(fd, env)))
        //  return (0);
    }
    return (1);
}

nt         set_cam(int fd, t_env *env)
{
    t_camera    cam;
    char        *str;
    char        **tab;

    while ((get_next_line(fd, &str)) <= 0)
    {
        cam.pos = coor_parse(&str, "-position[");
        ft_strdel(&str);
        if ((get_next_line(fd, &str)) <= 0)
            return (0);
        cam.vect = coor_parse(&str, "-vector[");
        ft_strdel(&str);
        env->lst = ft_lstnew(&cam, sizeof(t_camera));
        if ((get_next_line(fd, &str)) <= 0 && str != ';')
            return (0);
        if (strcmp("sphere", str) == 0)
            if (!(set_sph(fd, env)))
                return (0);
    }
    return (1);
}
