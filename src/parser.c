/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:45:26 by gboudrie          #+#    #+#             */
/*   Updated: 2016/12/16 14:25:54 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <fcntl.h>

double		value_parse(char **str, char *str2)
{
	int			value;

	value = 0;
//	if (ft_strncmp(str2, *str, ft_strlen(str2)) == 0)
		value = ft_atoi((*str) + ft_strlen(str2));
	return ((double)value);
}

int			color_parse(char **str)
{
	int			color;
	char		**tab;
	char		*tmp;

	color = 0;
//	if (ft_strncmp("-colour[", *str, 8) == 0)
//	{
	if (!(tab = ft_strsplit((*str) + 8, ' ')))
		return (0);
	tmp = (char *)(&color);
	color = 256 * 256 * ft_atoi(tab[0]);
	color += 256 * ft_atoi(tab[1]);
	color += ft_atoi(tab[2]);
	ft_tabdel((void ***)&tab);
//	}
	return (color);
}

t_dot_3d	coor_parse(char **str, char *str2)
{
	char		**tab;
	t_dot_3d	dot;

	dot.x = 0;
	dot.y = 0;
	dot.z = 0;
//	if (!(ft_strncmp(str2, *str, ft_strlen(str2))))
//	{
	if ((tab = ft_strsplit(*str + ft_strlen(str2), ' ')) == NULL)
		return (dot);
	dot.x = (double)ft_atoi(tab[0]);
	dot.y = (double)ft_atoi(tab[1]);
	dot.z = (double)ft_atoi(tab[2]);
	ft_tabdel((void ***)&tab);
//	}
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
		{
			if (!(set_cam(&fd, env)))
				return (0);
		}
		else if (strcmp("sphere{", str) == 0)
		{
			if (!(set_sph(&fd, env)))
				return (0);
		}
		else if (strcmp("plane{", str) == 0)
		{
			if (!(set_pln(&fd, env)))
				return (0);
		}
		else
			return (0);
		ft_strdel(&str);
	}
	return (1);
}
