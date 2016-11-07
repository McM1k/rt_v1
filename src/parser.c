/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:45:26 by gboudrie          #+#    #+#             */
/*   Updated: 2016/11/07 18:45:31 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//funct that will analyse the scene.txt and translate it into a list
#include "rtv1.h"
#include <unistd.h>



int		parser(char *arg, t_env *env)
{
	int		fd;
	char	*str;

	fd = open(arg, O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		if (strcmp("camera", str) == 0)
		{
			if ((set_cam(arg, env)))
				return (0);
		}
		else if (strcmp("sphere", str) == 0)
		{
			if ((set_sph(arg, env)))
				return (0);
		}
		else
			return (0);
	}
}
