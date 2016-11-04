/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:14:37 by gboudrie          #+#    #+#             */
/*   Updated: 2016/11/04 18:47:11 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_sphere
{
	char		*name;
	double		x;
	double		y;
	double		z;
	double		siz;
	int			col;
}				t_sphere;

typedef struct	s_plane
{
	char		*name;
	double		x;
	double		y;
	double		z;
	double		vx;
	double		vy;
	double		vz;
	double		col;
}				t_plane;

#endif
