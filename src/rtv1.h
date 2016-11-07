/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:14:37 by gboudrie          #+#    #+#             */
/*   Updated: 2016/11/07 18:45:33 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "mlx.h"
# include "../libft/libft.h"

typedef struct	s_camera
{
	char		*name;
	double		x;
	double		y;
	double		z;
	double		vx;
	double		vy;
	double		vz;
}

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

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*ig;
	char		*img;
	int			siz;
	int			bit;
	int			ed;
	void		*list;
}				t_env;

#endif
