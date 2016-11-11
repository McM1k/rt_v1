/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:14:37 by gboudrie          #+#    #+#             */
/*   Updated: 2016/11/11 13:12:31 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "mlx.h"
# include "../libft/libft.h"

typedef struct	s_dot_3d
{
	int			x;
	int			y;
	int			z;
}				t_dot_3d

typedef struct	s_camera
{
	t_dot_3d	pos;
	t_dot_3d	vect;
}				t_camera;

typedef struct	s_sphere
{
	t_dot_3d	pos;
	int			siz;
	int			col;
}				t_sphere;

typedef struct	s_plane
{
	t_dot_3d	pos;
	t_dot_3d	vect;
	int			col;
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
	t_list		*list;
}				t_env;

int				parser(char *arg, t_env *env);
int				set_sph(int fd, t_env *env);
int				set_cam(int fd, t_env *env);
t_dot_3d		coor_parse(char **str, char *str2);
int				color_parse(char **str);
#endif
