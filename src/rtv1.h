/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:14:37 by gboudrie          #+#    #+#             */
/*   Updated: 2017/01/12 16:05:11 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "mlx.h"
# include "../libft/libft.h"
# define SIZE_X 1000
# define SIZE_Y 500
# define PI 3.14159265358979323846

typedef struct	s_dot_3d
{
	double		x;
	double		y;
	double		z;
}				t_dot_3d;

typedef struct	s_obj
{
	char		name[4];
	t_dot_3d	pos;
	t_dot_3d	vect;
	double		siz;
	int			col;
}				t_obj;

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
int				set_con(int *fd, t_env *env);
int				set_cyl(int *fd, t_env *env);
int				set_pln(int *fd, t_env *env);
int				set_sph(int *fd, t_env *env);
int				set_cam(int *fd, t_env *env);
t_dot_3d		coor_parse(char **str, char *str2);
int				color_parse(char **str);
double			value_parse(char **str, char *str2);
void			raycast(t_env env);
double			collide_sph(t_obj r, t_obj o);
double			collide_pln(t_obj r, t_obj o);
double			collide_cyl(t_obj r, t_obj o);
double			collide_con(t_obj r, t_obj o);
t_dot_3d		rotate_vect_x(t_dot_3d vect, double angle);
t_dot_3d		rotate_vect_y(t_dot_3d vect, double angle);
t_dot_3d		rotate_vect_z(t_dot_3d vect, double angle);
#endif
