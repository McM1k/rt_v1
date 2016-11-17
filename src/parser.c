/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:45:26 by gboudrie          #+#    #+#             */
/*   Updated: 2016/11/15 13:47:11 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <unistd.h>

double		value_parse(char **str, char *str2)
{
	char		**tab;
	int			value;

	value = 0;
	if (ft_strcmp(str2, *str) == 0)
		value = ft_atoi((*str) + ft_strlen(str2));
	return ((double)value);
}

int			color_parse(char **str)
{
	int			color;
	char		**tab;
	char		*tmp;

	color = 0x00FFFFFF;
	if (ft_strcmp("-colour[", *str) == 0)
	{
		if (!(tab = ft_strsplit((*str) + 8, ' ')))
			return (0);
		tmp = (char *)(&color);
		tmp + 1 = ft_atoi(tab[0]);
		tmp + 2 = ft_atoi(tab[1]);
		tmp + 3 = ft_atoi(tab[2]);
		ft_tabdel(&tab);
	}
	return (color);
}

t_dot_3d	coor_parse(char **str, char *str2)
{
	char		**tab;
	t_dot_3d	dot;

	dot.x = 0;
	dot.y = 0;
	dot.z = 0;
	if (ft_strcmp(str2, *str) == 0)
	{
		if (!(tab = ft_strsplit((*str) + ft_strlen(str2), ' ')))
			return (0);
		dot.x = (double)ft_atoi(tab[0]);
		dot.y = (double)ft_atoi(tab[1]);
		dot.z = (double)ft_atoi(tab[2]);
		ft_tabdel(&tab);
	}
	return (dot);
}

int			parser(char *arg, t_env *env)
{
	int		fd;
	char	*str;

	fd = open(arg, O_RDONLY);

	while (get_next_line(fd, &str) > 0)
	{
		if (strcmp("camera{", str) == 0)
			if (!(set_cam(fd, env)))
				return (0);
		if (strcmp("sphere{", str) == 0)
			if (!(set_cam(fd, env)))
				return (0);
		else
			return (0);
		ft_strdel(&str);
	}
	return (1);
}
