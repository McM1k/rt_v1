/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:38:33 by gboudrie          #+#    #+#             */
/*   Updated: 2016/11/06 17:43:03 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int ac, char **av)
{
	t_env	env;

	if (ac == 2 && (env.mlx = mlx_init()) &&
		(env.win = mlx_new_window(env.mlx, SIZE_X, SIZE_Y, "Wolf3d")) &&
		(env.ig = mlx_new_image(env.mlx, SIZE_X, SIZE_Y)) &&
		(env.img = mlx_get_data_addr(env.ig, &(env.bit), &(env.siz), &(env.ed))))
	{
		mlx_put_image_to_window(env.mlx, env.win, env.ig, 0, 0);
		mlx_hook(env.win, 2, 0, key_funct, &env);
		mlx_hook(env.win, 17, 0, destroy_funct, &env);
		mlx_loop(env.mlx);
	}
	else
	{
		ft_putstr("memory allocation failed, closing program ");
		ft_putendl(av[0] + 2);
	}
	return (0);
}
